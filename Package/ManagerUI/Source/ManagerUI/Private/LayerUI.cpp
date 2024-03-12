// Fill out your copyright notice in the Description page of Project Settings.

//
#include "LayerUI.h"
#include "Blueprint/UserWidget.h"

//
UE_DISABLE_OPTIMIZATION
void ULayerUI::PushToStack(UUserWidget* widget)
{
	if (widget)
	{
		OnWidgetPushed_Implementation(widget);
		WidgetStack.Push(widget);
	}
	//WidgetPushedDelegate.Broadcast();
}

UUserWidget* ULayerUI::PopFromStack()
{
	if(WidgetStack.IsEmpty())
		return nullptr;

	UUserWidget* widget = WidgetStack.Pop();
	//widget->SetVisibility(ESlateVisibility::Collapsed);
	OnWidgetPopped_Implementation(widget);

	return widget;
}

void ULayerUI::SetVisibilityOfLayer(ESlateVisibility visibility)
{
	for (auto& widget : WidgetStack)
	{
		if (widget)
		{
			widget->SetVisibility(visibility);
		}
	}
	//LayerVisibilityChangedDelegate.Broadcast(visibility);
}

void ULayerUI::ClearStack()
{
	OnLayerCleared();
	WidgetStack.Empty();
}

void ULayerUI::OnWidgetPushedOthers_Implementation(const TArray<ULayerUI*>& otherLayers)
{

}

void ULayerUI::OnWidgetPoppedOthers_Implementation(const TArray<ULayerUI*>& otherLayers)
{

}

void ULayerUI::OnLayerCleared_Implementation()
{
	SetVisibilityOfLayer(ESlateVisibility::Collapsed);
}

void ULayerUI::OnWidgetPushed_Implementation(UUserWidget* widget)
{
	if(widget)
		widget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);

	switch (Type)
	{
	case SINGLE:
		SetVisibilityOfLayer(ESlateVisibility::Collapsed);
		//ClearStack();
		break;
	case MULTIPLE:

		break;
	default:
		break;
	}
}
void ULayerUI::OnWidgetPopped_Implementation(UUserWidget* widget)
{
	switch (Type)
	{
	case SINGLE:
		// hide popped widget
		if(widget)
		{
			widget->SetVisibility(ESlateVisibility::Collapsed);
		}
		// how widget on top of the stack
		if (WidgetStack.IsEmpty())
			return;
		WidgetStack.Top()->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
		break;
	case MULTIPLE:

		break;
	default:
		break;
	}
}
UE_ENABLE_OPTIMIZATION