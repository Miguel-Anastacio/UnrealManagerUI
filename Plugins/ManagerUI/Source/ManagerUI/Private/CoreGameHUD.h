// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "LayerManagerHUD.h"
#include "CoreGameHUD.generated.h"

/**
 * 
 */
UCLASS()
class ACoreGameHUD : public ALayerManagerHUD
{
	GENERATED_BODY()
public:
	void BeginPlay() override;

protected:
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

	//UPROPERTY()
	//TObjectPtr<class UUserWidget> MainMenuWidget;
	//UPROPERTY()
	//TObjectPtr<class UUserWidget> OptionsMenuWidget;
	//UPROPERTY()
	//TObjectPtr<class UUserWidget> OptionsMenuWidget;
	
};
