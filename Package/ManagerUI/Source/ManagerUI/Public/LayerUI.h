// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"

#include "LayerUI.generated.h"


// How many widgets can be visible at the same time
// SINGLE - one
// MULTIPLE - several
UENUM(BlueprintType)
enum LayerType
{
	SINGLE UMETA(DisplayName = "Single"),
	MULTIPLE   UMETA(DisplayName = "Multiple"),
};

class UUserWidget;

/**
 * 
 */
UCLASS(MinimalAPI, Blueprintable, BlueprintType)
class ULayerUI : public UObject
{
	GENERATED_BODY()

public:
	//ULayerUI();
	void PushToStack(UUserWidget* widget);
	UUserWidget* PopFromStack();

	UFUNCTION(BlueprintCallable, Category = Layer)
	void SetVisibilityOfLayer(ESlateVisibility visibility);

	UFUNCTION(BlueprintCallable, Category = Layer)
	void ClearStack();

	// this defines the impact that pushing to this layer has on the other layers
	UFUNCTION(BlueprintNativeEvent, Category = "Layer Reaction")
	void OnWidgetPushedOthers(const TArray<ULayerUI*>& otherLayers);
	virtual void OnWidgetPushedOthers_Implementation(const TArray<ULayerUI*>& otherLayers);

	// this defines the impact that pushing to this layer has on the other layers
	UFUNCTION(BlueprintNativeEvent, Category = Layer)
	void OnWidgetPoppedOthers(const TArray<ULayerUI*>& otherLayers);
	virtual void OnWidgetPoppedOthers_Implementation(const TArray<ULayerUI*>& otherLayers);

	// this defines the impact that clearing this layer has on its widgets 
	UFUNCTION(BlueprintNativeEvent, Category = Layer)
	void OnLayerCleared();
	// by default it just changes their visibility to collapsed
	virtual void OnLayerCleared_Implementation();


public:
	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = true), Category = Layer);
	TEnumAsByte<LayerType> Type = SINGLE;
protected:
	UPROPERTY(VisibleAnywhere, Category = Layer)
	TArray<class UUserWidget*> WidgetStack;

	// called when pushing a widget by default uses the layerType to hide/not hide the other widgets
	UFUNCTION(BlueprintNativeEvent, Category = Layer)
	void OnWidgetPushed(class UUserWidget* widget);
	virtual void OnWidgetPushed_Implementation(class UUserWidget* widget);

	// called when popping a widget by default - nothing
	UFUNCTION(BlueprintNativeEvent, Category = Layer)
	void OnWidgetPopped(class UUserWidget* widget);
	virtual void OnWidgetPopped_Implementation(class UUserWidget* widget);

};
