// Copyright Maniform Studio

#include "UI/Widget/AuraUserWidget.h"
#include "AuraUserWidget.h"


void UAuraUserWidget::SetWidgetController(UObject* InWidgetController)
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}
