// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UILayerManagerFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UUILayerManagerFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "UI Utils")
	static void AddWidgetToLayer(TSubclassOf<class UUserWidget> widgetClass, const FString& layerName, APlayerController* controller);
};
