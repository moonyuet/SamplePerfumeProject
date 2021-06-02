// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "ColorBlock.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT2_API UColorBlock : public UWidget
{
	GENERATED_BODY()
public: 
	UColorBlock();
protected:
	virtual TSharedRef<SWidget> RebuildWidget() override;

#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Color")
	FLinearColor CurrentColor;
	void UpdateColor(FLinearColor NewColor);
	void CancelColor(FLinearColor OldColor);
	void CloseColorPicker(const TSharedRef<SWindow>& ColorWindow);
	void ReleaseSlateResources(bool bReleaseChildren);
	FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent);

public:
	FLinearColor GetColor() const;
private:
	TSharedPtr<class SColorBlock> MyColorBlock;
	TSharedPtr<class SWindow> SlateWindow;
protected:
	TSharedPtr<class SColorPicker> ColorPicker;
};
