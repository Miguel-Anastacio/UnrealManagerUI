// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SlateWrapperTypes.h"

#include "LayerUI.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnLayerVisibilityChangedSignature, ESlateVisibility, state);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnWidgetPushedSignature);

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
UCLASS(BlueprintType)
class ULayerUI : public UObject
{
	GENERATED_BODY()

public:
	//ULayerUI();
	void PushToStack(UUserWidget* widget);
	UUserWidget* PopFromStack();
	void SetVisibilityOfLayer(ESlateVisibility visibility);

	void ClearStack();
	//UPROPERTY(BlueprintAssignable, BlueprintCallable)
	//FOnLayerVisibilityChangedSignature LayerVisibilityChangedDelegate;

	UPROPERTY(BlueprintReadWrite, meta = (ExposeOnSpawn = true));
	TEnumAsByte<LayerType> Type = SINGLE;
protected:
	UPROPERTY()
		TArray<class UUserWidget*> WidgetStack;

	UFUNCTION(BlueprintNativeEvent)
	void OnWidgetPushed();
	virtual void OnWidgetPushed_Implementation();

};
