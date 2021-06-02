// Fill out your copyright notice in the Description page of Project Settings.


#include "MaterialSetsParam.h"
#include "Components/StaticMeshComponent.h"

void UMaterialSetsParam::MaterialSet(UStaticMeshComponent* BotCup, UStaticMeshComponent* BotTop, UStaticMeshComponent* BotBody, UStaticMeshComponent* BotCase, UMaterialInterface* CupMat, UMaterialInterface* TopMat, UMaterialInterface* BodyMat, UMaterialInterface* CaseMat)
{
	int32 idx = 0;

	BotCup->SetMaterial(idx,CupMat);
	BotTop->SetMaterial(idx,TopMat);
	BotBody->SetMaterial(idx,BodyMat);
	BotCase->SetMaterial(idx, CaseMat);
}