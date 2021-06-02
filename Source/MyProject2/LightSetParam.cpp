// Fill out your copyright notice in the Description page of Project Settings.


#include "LightSetParam.h"
#include "Components/LightComponent.h"

void ULightSetParam::FixedBasicLights(ULightComponent* Keylight, ULightComponent* Filllight, float KeylightIntensity, float lightmultiplier)
{
	Keylight->SetIntensity(KeylightIntensity);

	if (lightmultiplier > 0)
	{
		Filllight->SetIntensity(KeylightIntensity / lightmultiplier);
	}
	else
	{
		Filllight->SetIntensity(KeylightIntensity * lightmultiplier);
	}
}
void ULightSetParam::FixedFrontBackLight(ULightComponent* Frontlight, ULightComponent* Backlight, float FrontlightIntensity)
{
	float secretmultiplier = 0.8f;
	Frontlight->SetIntensity(FrontlightIntensity);
	Backlight->SetIntensity(FrontlightIntensity * secretmultiplier);
}
float ULightSetParam::FixedFrontlightCalculator(ULightComponentBase* Keylight, ULightComponentBase* Filllight, float multiplier)
{
	float keyExposure = Keylight->Intensity;
	float fillExposure = Filllight->Intensity;
	float frontExposure = (keyExposure + fillExposure) / multiplier;

	return frontExposure;
}
void ULightSetParam::SetLightIntensity(ULightComponent* Key, ULightComponent* Fill, ULightComponent* Side, ULightComponent* Left, ULightComponent* Kick, float KeyIntensity, float FillIntensity, float SideIntensity, float LeftIntensity, float KickIntensity)
{
	Key->SetIntensity(KeyIntensity);
	Fill->SetIntensity(FillIntensity);
	Side->SetIntensity(SideIntensity);
	Left->SetIntensity(LeftIntensity);
	Kick->SetIntensity(KickIntensity);
}
void ULightSetParam::SetLightColor(ULightComponent* Key, ULightComponent* Fill, ULightComponent* Front, ULightComponent* Back, ULightComponent* Kick, FLinearColor KeyColor, FLinearColor FillColor, FLinearColor FrontColor, FLinearColor BackColor, FLinearColor KickColor)
{
	Key->SetLightColor(KeyColor);
	Fill->SetLightColor(FillColor);
	Front->SetLightColor(FrontColor);
	Back->SetLightColor(BackColor);
	Kick->SetLightColor(KickColor);
}