// Fill out your copyright notice in the Description page of Project Settings.


#include "UIActionsComponent.h"
#include "../Plugins/ManagerUI/Source/ManagerUI/Public/CoreGameHUD.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"
// Sets default values for this component's properties
UUIActionsComponent::UUIActionsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}

void UUIActionsComponent::BindActions(UEnhancedInputComponent* enhancedInputComponent)
{
	enhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Started, this, &UUIActionsComponent::Pause);
	enhancedInputComponent->BindAction(InventoryAction, ETriggerEvent::Started, this, &UUIActionsComponent::ToggleInventory);
}
void UUIActionsComponent::AddUIMappingContext(UEnhancedInputLocalPlayerSubsystem* subsystem)
{
	subsystem->AddMappingContext(UIMappingContext, MappingContextPriority);
}

void UUIActionsComponent::RemoveUIMappingContext(UEnhancedInputLocalPlayerSubsystem* subsystem)
{
	subsystem->RemoveMappingContext(UIMappingContext);
}

void UUIActionsComponent::ToggleInventory()
{
	if (!IsValid(GetOwner()))
	{
		return;
	}

	APlayerController* controller = Cast<APlayerController>(GetOwner());
	if (!IsValid(controller))
	{
		return;
	}

	ACoreGameHUD* hud = Cast<ACoreGameHUD>(controller->GetHUD());
	if (IsValid(hud))
	{
		hud->ToggleInventory();
	}
}

void UUIActionsComponent::Pause()
{
	if (!IsValid(GetOwner()))
	{
		return;
	}

	APlayerController* controller = Cast<APlayerController>(GetOwner());
	if (!IsValid(controller))
	{
		return;
	}

	ACoreGameHUD* hud = Cast<ACoreGameHUD>(controller->GetHUD());
	if (IsValid(hud))
	{
		hud->TogglePause();
	}
}



// Called when the game starts
void UUIActionsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


//// Called every frame
//void UUIActionsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//	// ...
//}

