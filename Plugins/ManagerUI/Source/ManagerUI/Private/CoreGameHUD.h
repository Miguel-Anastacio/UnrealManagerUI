// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LayerManagerHUD.h"
#include "CoreGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class MANAGERUI_API ACoreGameHUD : public ALayerManagerHUD
{
	GENERATED_BODY()
public:
	void BeginPlay() override;

	// EXAMPLE ONLY
	// This is an example event for like an inventory widget
	UFUNCTION(BlueprintNativeEvent)
	void ToggleInventory();
	void ToggleInventory_Implementation();
	UFUNCTION(BlueprintCallable)
	void SetInventoryWidget(class UUserWidget* widget);
	///////////////////////////////////////////////////


	UFUNCTION(BlueprintCallable)
	void SetHUDWidget(class UUserWidget* widget);

	// You can define the pause behaviour either in blueprint or c++
	UFUNCTION(BlueprintNativeEvent)
	void TogglePause();
	void TogglePause_Implementation();

protected:
	// This are classes of widgets that can be spawned in c++
	UPROPERTY(EditAnywhere, Category = "Menus")
	TSubclassOf<class UUserWidget> MainMenuClass;
	UPROPERTY(EditAnywhere, Category = "Menus")
	TSubclassOf<class UUserWidget> OptionsMenuClass;
	UPROPERTY(EditAnywhere, Category = "Game")
	TSubclassOf<class UUserWidget> HUDClass;
	UPROPERTY(EditAnywhere, Category = "Game")
	TSubclassOf<class UUserWidget> InventoryClass;
	UPROPERTY(EditAnywhere, Category = "Modals")
	TSubclassOf<class UUserWidget> ConfirmModalClass;

	// References to specific widgets, only have to define in c++ and set if you wish to 
	// use them in code
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<class UUserWidget> HUDWidget;
	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<class UUserWidget> InventoryWidget;
	//UPROPERTY(BlueprintReadWrite)
	//TObjectPtr<class UUserWidget> PauseWidget;

	

};
