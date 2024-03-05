// Fill out your copyright notice in the Description page of Project Settings.

//
#include "LayerUI.h"
#include "Blueprint/UserWidget.h"

//
void ULayerUI::PushToStack(UUserWidget* widget)
{
	if (widget)
	{
		OnWidgetPushed_Implementation();
		WidgetStack.Push(widget);

	}
	//WidgetPushedDelegate.Broadcast();
}

UUserWidget* ULayerUI::PopFromStack()
{
	if(WidgetStack.IsEmpty())
		return nullptr;

	return WidgetStack.Pop();
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
	SetVisibilityOfLayer(ESlateVisibility::Collapsed);
	WidgetStack.Empty();
}

void ULayerUI::OnWidgetPushed_Implementation()
{
	switch (Type)
	{
	case SINGLE:
		ClearStack();
		break;
	case MULTIPLE:

		break;
	default:
		break;
	}
}
