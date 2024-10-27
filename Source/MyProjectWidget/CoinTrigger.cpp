// Fill out your copyright notice in the Description page of Project Settings.


#include "CoinTrigger.h"
#include "Components/SphereComponent.h"

ACoinTrigger::ACoinTrigger()
{
	OnActorBeginOverlap.AddDynamic(this, &ACoinTrigger::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &ACoinTrigger::OnOverlapEnd);

	CoinCount = 0;

	Player = nullptr;
	CoinHUD = nullptr;
}


void ACoinTrigger::BeginPlay()
{
	Super::BeginPlay();
	//Player = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;
	//CoinHUD = Cast<ACoinHUD>(Player->GetHUD());
	Player = GetWorld()->GetFirstPlayerController();
	if (Player)
	{
		CoinHUD = Cast<ACoinHUD>(Player->GetHUD());
	}
}

void ACoinTrigger::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// Check if the overlapping actor is the player character
	if (OtherActor && OtherActor != this)
	{
		CoinCount++;
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Overlap Begin: %d"), CoinCount));

		//APlayerController* Player = GetWorld()->GetFirstPlayerController();
		//ACoinHUD* CoinHUD = Cast<ACoinHUD>(Player->GetHUD());
		CoinHUD->UpdateCoinWidget(CoinCount);
	}
}

void ACoinTrigger::OnOverlapEnd(class AActor* OverlappedActor, class AActor* OtherActor)
{
	// Check if the overlapping actor is the player character
	if (OtherActor && OtherActor != this)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlap End"));
	}
}
