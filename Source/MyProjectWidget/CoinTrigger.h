// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerSphere.h"
#include "CoinClass.h"
#include "GameFramework/PlayerController.h"
#include "CoinHUD.h"
#include "CoinTrigger.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECTWIDGET_API ACoinTrigger : public ATriggerSphere
{
	GENERATED_BODY()
protected:
	virtual void BeginPlay() override;
public:
	ACoinTrigger();

	APlayerController* Player;
	ACoinHUD* CoinHUD;

	int CoinCount;

	UFUNCTION()
	virtual void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	UFUNCTION()
	virtual void OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor);
	
};
