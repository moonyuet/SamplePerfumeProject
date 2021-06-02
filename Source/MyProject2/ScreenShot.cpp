// Fill out your copyright notice in the Description page of Project Settings.


#include "ScreenShot.h"
#include "HighResScreenshot.h"

bool UScreenShot::HighResScreenShot(int width, int height, FString filename, bool SetAlpha)
{
	
	GetHighResScreenshotConfig().SetResolution(width, height, 100.f);
	GetHighResScreenshotConfig().FilenameOverride = FPaths::ProjectDir() / TEXT("Snapshots") / filename;

	FScreenshotRequest::RequestScreenshot(false);

	return false;
}
