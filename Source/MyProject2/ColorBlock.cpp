// Fill out your copyright notice in the Description page of Project Settings.


#include "ColorBlock.h"
#include "Widgets/Colors/SColorBlock.h"
#include "Blueprint/UserWidget.h"
#include "AppFramework/Public/Widgets/Colors/SColorPicker.h"
#define LOCTEXT_NAMESPACE "UColorBlock"
UColorBlock::UColorBlock()
	:CurrentColor(1.f, 1.f, 1.f, 1.f)
{

}

TSharedRef<SWidget> UColorBlock::RebuildWidget()
{
	auto OnGetColor = [&]()
	{
		return CurrentColor;
	};
	MyColorBlock = SNew(SColorBlock)
		.ShowBackgroundForAlpha(true)
		.Color_Lambda(OnGetColor)
		.IgnoreAlpha(false)
		.ColorIsHSV(false)
		.Size(FVector2D(70.f, 12.0f))
		.OnMouseButtonDown(BIND_UOBJECT_DELEGATE(FPointerEventHandler, OnMouseButtonDown));


	return MyColorBlock.ToSharedRef();
}
#if WITH_EDITOR
const FText UColorBlock::GetPaletteCategory()
{
	return LOCTEXT("ColoPicker", "ColoPicker");
}
#endif
void UColorBlock::UpdateColor(FLinearColor NewColor)
{
	CurrentColor = NewColor;
}

void UColorBlock::CancelColor(FLinearColor OldColor)
{
	CurrentColor = OldColor;
}

void UColorBlock::CloseColorPicker(const TSharedRef<SWindow>& ColorWindow)
{	
}

void UColorBlock::ReleaseSlateResources(bool bReleaseChildren)
{
	Super::ReleaseSlateResources(bReleaseChildren);


	ColorPicker.Reset();
	SlateWindow.Reset();
	MyColorBlock.Reset();
}

FReply UColorBlock::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	SlateWindow = FSlateApplication::Get().AddWindow(
		SNew(SWindow)
		.Title(FText::FromString("ColorPicker"))
		.ClientSize(SColorPicker::DEFAULT_WINDOW_SIZE)
	);

	ColorPicker = SNew(SColorPicker)
		.UseAlpha(true)
		.OnlyRefreshOnOk(false)
		.ParentWindow(SlateWindow)
		.TargetColorAttribute(CurrentColor)
		.OnColorCommitted(BIND_UOBJECT_DELEGATE(FOnLinearColorValueChanged, UpdateColor))
		.OnColorPickerCancelled(BIND_UOBJECT_DELEGATE(FOnLinearColorValueChanged, CancelColor))
		.OnColorPickerWindowClosed(BIND_UOBJECT_DELEGATE(FOnWindowClosed, CloseColorPicker))
		.ExpandAdvancedSection(true);

	if (SlateWindow.IsValid())
	{
		SlateWindow->SetContent(ColorPicker.ToSharedRef());
	}

	return FReply::Unhandled();
}

FLinearColor UColorBlock::GetColor() const
{
	return CurrentColor;
}
