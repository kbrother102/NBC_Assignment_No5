// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"
#include "Engine/Engine.h"
#include "kismet/KismetMathLibrary.h"
#include "kismet/GameplayStatics.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  
	// You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMyActor::UDTurn()
{
	if (RootComponent)
	{
		RootComponent->SetWorldRotation(FRotator(UKismetMathLibrary::RandomRotator()));
	}
	FRotator currota = RootComponent->GetComponentRotation();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Emerald, TEXT("현재 각도 : ") + currota.ToString());
	}
}
void AMyActor::UDMove()
{
	double RandX = FMath::RandRange(-1000, 1000);
	double RandY = FMath::RandRange(-1000, 1000);
	double RandZ = FMath::RandRange(0, 1000);
	if (RootComponent)
	{
		RootComponent->SetWorldLocation(FVector(RandX, RandY, RandZ));
	}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, TEXT("현재 위치") + GetActorLocation().ToString());
	}

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.1, FColor::Blue, TEXT("TestMessege"));
	}

	if (RootComponent)
	{
		RootComponent->SetWorldLocation(FVector(0, 50, 0));
	}

	for (int i = 0; i < 10; i++)
	{
		UDTurn();
		UDMove();
	}

}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

