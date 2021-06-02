// Fill out your copyright notice in the Description page of Project Settings.


#include "LightDev.h"
#include "Components/PointLightComponent.h"
ALightDev::ALightDev()
{
	Keylight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Keylight"));
	Keylight->SetupAttachment(RootComponent);
	Keylight->SetRelativeLocation(FVector(100, 10, 30));
	Keylight->SetIntensity(1000.f);

	Filllight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Filllight"));
	Filllight->SetupAttachment(RootComponent);
	Filllight->SetRelativeLocation(FVector(-110, -30, 40));
	Filllight->SetIntensity(800.f);

	Sidelight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Sidelight"));
	Sidelight->SetupAttachment(RootComponent);
	Sidelight->SetRelativeLocation(FVector(-80, -90, 50));
	Sidelight->SetIntensity(800.f);

	LeftLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Leftlight"));
	LeftLight->SetupAttachment(RootComponent);
	LeftLight->SetRelativeLocation(FVector(-30, 70, 30));
	LeftLight->SetIntensity(500.f);

	KickLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("Kicklight"));
	KickLight->SetupAttachment(RootComponent);
	KickLight->SetRelativeLocation(FVector(10, -110, 100));
	KickLight->SetIntensity(800.f);

}