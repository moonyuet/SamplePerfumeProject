// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LightSetParam.generated.h"

class ULightComponentBase;
class ULightComponent;
/**
 * 
 */
UCLASS()
class MYPROJECT2_API ULightSetParam : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
		UFUNCTION(BlueprintCallable, Category= "Custom Light", meta = (Keywords = "Save"))
		static void FixedBasicLights(ULightComponent* Keylight, ULightComponent* Filllight, float KeylightIntensity, float lightmultiplier);
		UFUNCTION(BlueprintCallable, Category = "Custom Light", meta = (Keywords = "Save"))
		static void FixedFrontBackLight(ULightComponent* Frontlight, ULightComponent* Backlight, float FrontlightIntensity);
		UFUNCTION(BlueprintCallable, Category = "Custom Light", meta = (Keywords = "Save"))
		static float FixedFrontlightCalculator(ULightComponentBase* Keylight, ULightComponentBase* Filllight, float multiplier);
		UFUNCTION(BlueprintCallable, Category = "Custom Light", meta = (Keywords = "Save"))
		static void SetLightIntensity(ULightComponent* Key, ULightComponent* Fill, ULightComponent* Side, ULightComponent* Left, ULightComponent* Kick, float KeyIntensity, float FillIntensity, float SideIntensity, float LeftIntensity, float KickIntensity);
		UFUNCTION(BlueprintCallable, Category = "Custom Light", meta = (Keywords = "Save"))
		static void SetLightColor(ULightComponent* Key, ULightComponent* Fill, ULightComponent* Front, ULightComponent* Back, ULightComponent* Kick, FLinearColor KeyColor, FLinearColor FillColor, FLinearColor FrontColor, FLinearColor BackColor, FLinearColor KickColor);
	
};
