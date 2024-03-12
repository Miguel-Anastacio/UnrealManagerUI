// Fill out your copyright notice in the Description page of Project Settings.


#include "UILayerManagerFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "LayerManagerHUD.h"
#include "Blueprint/UserWidget.h"

UUserWidget* UUILayerManagerFunctionLibrary::AddWidgetToLayer(TSubclassOf<class UUserWidget> widgetClass, const FString& layerName, APlayerController* controller)
{
	UUserWidget* widget = CreateWidget<UUserWidget>(controller, widgetClass);
	if(!widget)
		return nullptr;

	widget->AddToViewport();
	ALayerManagerHUD* hud = Cast<ALayerManagerHUD>(controller->GetHUD());
	if (hud)
	{
		hud->PushToLayer(layerName, widget);
		return widget;
	}

	return nullptr;
}

void UUILayerManagerFunctionLibrary::ToggleWidgetVisibility(UUserWidget* widget, const FString& layerName, APlayerController* controller)
{
	ALayerManagerHUD* hud = Cast<ALayerManagerHUD>(controller->GetHUD());
	if (hud && widget)
	{
		if (widget->IsVisible())
		{
			hud->PopFromLayer(layerName);
		}
		else
		{
			hud->PushToLayer(layerName, widget);
		}
	}
}
