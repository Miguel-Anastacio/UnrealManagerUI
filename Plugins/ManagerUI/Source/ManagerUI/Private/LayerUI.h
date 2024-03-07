// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"

#include "LayerUI.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLayerVisibilityChangedSignature, ESlateVisibility, state);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWidgetPushedSignature);

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
//USTRUCT(BlueprintType)
//struct FUILayer
//{
//	GENERATED_USTRUCT_BODY()
//	FUILayer() {};
//
//	void PushToStack(UUserWidget* widget);
//	UUserWidget* PopFromStack();
//	void SetVisibilityOfLayer(ESlateVisibility visibility);
//
//
//	//UFUNCTION(BlueprintNativeEvent)
//	//void OnWidgetPushed();
//
//	//virtual void OnWidgetPushed_Implementaion();
//
//	UPROPERTY(BlueprintAssignable, BlueprintCallable)
//	FOnLayerVisibilityChangedSignature LayerVisibilityChangedDelegate;
//
//	//UPROPERTY(BlueprintAssignable, BlueprintCallable)
//	//FOnWidgetPushedSignature WidgetPushedDelegate;
//
//	LayerType Type = SINGLE;
//
//private:
//	UPROPERTY()
//	TArray<UUserWidget*> WidgetStack;
//
//
//};



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

	UFUNCTION(BlueprintCallable)
	void SetVisibilityOfLayer(ESlateVisibility visibility);

	UFUNCTION(BlueprintCallable)
	void ClearStack();

	// this defines the impact that pushing to this layer has on the other layers
	UFUNCTION(BlueprintNativeEvent)
	void OnWidgetPushedOthers(const TArray<ULayerUI*>& otherLayers);
	virtual void OnWidgetPushedOthers_Implementation(const TArray<ULayerUI*>& otherLayers);

	// this defines the impact that pushing to this layer has on the other layers
	UFUNCTION(BlueprintNativeEvent)
	void OnWidgetPoppedOthers(const TArray<ULayerUI*>& otherLayers);
	virtual void OnWidgetPoppedOthers_Implementation(const TArray<ULayerUI*>& otherLayers);

	//UPROPERTY(BlueprintAssignable, BlueprintCallable)
	//FOnLayerVisibilityChangedSignature LayerVisibilityChangedDelegate;

public:
	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = true));
	TEnumAsByte<LayerType> Type = SINGLE;
protected:
	UPROPERTY(VisibleAnywhere)
		TArray<class UUserWidget*> WidgetStack;

	// called when pushing a widget by default uses the layerType to hide/not hide the other widgets
	UFUNCTION(BlueprintNativeEvent)
	void OnWidgetPushed();
	virtual void OnWidgetPushed_Implementation();

	// called when popping a widget by default - nothing
	UFUNCTION(BlueprintNativeEvent)
	void OnWidgetPopped();
	virtual void OnWidgetPopped_Implementation();

};
