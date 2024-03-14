// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "LayerManagerHUD.generated.h"

/**
 * 
 */
class UUserWidget;
//class LayerUI
UCLASS( Blueprintable, BlueprintType)
class MANAGERUI_API ALayerManagerHUD : public AHUD
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Layer)
	void RegisterDefaultLayer(const FString& name);
	UFUNCTION(BlueprintCallable, Category = Layer)
	void RegisterLayer(const FString& name, class ULayerUI* layer, bool current = false);
	UFUNCTION(BlueprintCallable, Category = Layer)
	void RemoveLayer(const FString& name);

	//	Adds widget to layer, if layer does not exist a new one is created
	UFUNCTION(BlueprintCallable, Category = Layer)
	void PushToLayer(const FString& name, class UUserWidget* widget);
	UFUNCTION(BlueprintCallable, Category = Layer)
	UUserWidget* PopFromLayer(const FString& name);
	UFUNCTION(BlueprintCallable, Category = Layer)
	UUserWidget* PopFromCurrentLayer();

	UFUNCTION(BlueprintCallable, Category = Layer)
	void ClearAllLayers();
	UFUNCTION(BlueprintCallable, Category = Layer)
	void ClearLayer(const FString& name);


	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Layer)
	ULayerUI* GetLayer(const FString& name) const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Layer)
	FString GetCurrentLayerTag() const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Layer)
	UUserWidget* PeakLayer(const FString& name) const;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = Layer)
	bool IsWidgetOnTopOfLayer(const FString& name, class UUserWidget* widget) const;


public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Layer)
	FString CurrentLayerID;

protected:
	UPROPERTY(VisibleAnywhere, Category = Layer)
	TMap<FString, class ULayerUI*> LayersUI;

	UPROPERTY()
	TArray<FString> LayerOrder;
};
