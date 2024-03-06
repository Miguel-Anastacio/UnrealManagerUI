// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LayerUI.h"
#include "LayerManagerHUD.generated.h"

/**
 * 
 */
class UUserWidget;
UCLASS(MinimalAPI, Blueprintable, BlueprintType)
class ALayerManagerHUD : public AHUD
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void RegisterDefaultLayer(const FString& name);
	UFUNCTION(BlueprintCallable)
	void RegisterLayer(const FString& name, class ULayerUI* layer, bool current = false);

	UFUNCTION(BlueprintCallable)
	void RemoveLayer(const FString& name);
	//	Adds widget to layer, if layer does not exist a new one is created
	UFUNCTION(BlueprintCallable)
	void PushToLayer(const FString& name, class UUserWidget* widget);
	UFUNCTION(BlueprintCallable)
	UUserWidget* PopFromLayer(const FString& name);
	UFUNCTION(BlueprintCallable)
	UUserWidget* PopFromCurrentLayer();

	UFUNCTION(BlueprintCallable)
		ULayerUI* GetLayer(const FString& name);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FString CurrentLayerID;

protected:
	UPROPERTY()
	TMap<FString, class ULayerUI*> LayersUI;
};
