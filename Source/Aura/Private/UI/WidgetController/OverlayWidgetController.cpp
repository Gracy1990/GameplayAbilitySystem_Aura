// Copyright Maniform Studio

#include "UI/WidgetController/OverlayWidgetController.h"
#include "AuraAttributeSet.h"

#include "AuraAbilitySystemComponent.h"
#include "UObject/ConstructorHelpers.h"

// Constructor: Load the DataTable asset
UOverlayWidgetController::UOverlayWidgetController()
{
	// Replace the path below with your actual DataTable asset path
	static ConstructorHelpers::FObjectFinder<UDataTable> DataTableRef(
		TEXT("/Game/Blueprints/UI/Data/DT_MessageWidgetData.DT_MessageWidgetData")
	);

	if (DataTableRef.Succeeded())
	{
		MessageWidgetDataTable = DataTableRef.Object;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to load DataTable at /Game/Blueprints/UI/Data/DT_MessageWidgetData.DT_MessageWidgetData"));
	}
}
void UOverlayWidgetController::BroadcastInitialValues()
{
	if (!AttributeSet) return;

	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(AuraAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(AuraAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindcallbacksToDependencies()
{
	if (!AttributeSet || !AbilitySystemComponent) return;

	const UAuraAttributeSet* AuraAttributeSet = CastChecked<UAuraAttributeSet>(AttributeSet);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnHealthChanged.Broadcast(Data.NewValue);
			}
		);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetMaxHealthAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxHealthChanged.Broadcast(Data.NewValue);
			}
		);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetManaAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnManaChanged.Broadcast(Data.NewValue);
			}
		);

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetMaxManaAttribute()).AddLambda(
			[this](const FOnAttributeChangeData& Data)
			{
				OnMaxManaChanged.Broadcast(Data.NewValue);
			}
		);

	Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda(
		[this](const FGameplayTagContainer& AssetTags)
		{
			// Request the "Message" tag once.
			FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
			for (const FGameplayTag& Tag : AssetTags)
			{
				// Check if the current Tag matches the "Message" tag.
				if (Tag.MatchesTag(MessageTag))
				{
					const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
					if (Row)
					{
						MessageWidgetRowDelegate.Broadcast(*Row);
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("No matching row found for Tag: %s"), *Tag.ToString());
					}
				}
			}
		}
	);
}
