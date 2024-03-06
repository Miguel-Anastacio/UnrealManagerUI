// Fill out your copyright notice in the Description page of Project Settings.


#include "UILayerManagerFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "LayerManagerHUD.h"
#include "Blueprint/UserWidget.h"

void UUILayerManagerFunctionLibrary::AddWidgetToLayer(TSubclassOf<class UUserWidget> widgetClass, const FString& layerName, APlayerController* controller)
{
	UUserWidget* widget = CreateWidget<UUserWidget>(controller, widgetClass);
	widget->AddToViewport();

	ALayerManagerHUD* hud = Cast<ALayerManagerHUD>(controller->GetHUD());
	if (hud)
	{
		hud->PushToLayer(layerName, widget);
	}
}
