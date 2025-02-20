// Copyright Maniform Studio

using UnrealBuildTool;

public class Aura : ModuleRules
{
	public Aura(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "GameplayAbilities" });

		PrivateDependencyModuleNames.AddRange(new string[] { "GameplayTags", "GameplayTasks", "NavigationSystem", "Niagara"});
        
		PublicIncludePaths.AddRange(new string[] { "Aura/Public/UI/Widget" });

        PublicIncludePaths.AddRange(new string[]
{
            "Aura/Public",

            "Aura/Public/AbilitySystem"  // Add this line for your AbilitySystem includes
    });

        PrivateIncludePaths.AddRange(new string[]
        {
            "Aura/Private",
        });
 
		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
