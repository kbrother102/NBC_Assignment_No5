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

    

    SetActorLocation(FVector(RandX, RandY, RandZ));
	distance_ += FVector::Dist(Vec1_, GetActorLocation());
	Vec1_ = FVector(RandX, RandY, RandZ);
    tpcnt_++;

	RandomEvent();
	//bool event = FMath::RandBool(); //50% 니까 0 아니면 1, 1/2
	//if (event)
	//{
	//	
	//}

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Emerald, TEXT("현재 위치") + GetActorLocation().ToString());
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Blue, FString::Printf(TEXT("이동횟수 : %d"), tpcnt_));
		
	}

}

void AMyActor::RandomEvent()
{
	bool event = FMath::RandBool(); //50% 니까 0 아니면 1, 1/2
	if (event)
	{
		if (MySpawnClass)
		{
			GetWorld()->SpawnActor<AActor>(MySpawnClass, GetActorLocation(), FRotator(0, 0, 0), FActorSpawnParameters());
			GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Magenta, TEXT("뿌직"));
			evcnt_++;
		}
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
	
	//for (int i = 0; i < 10; i++)
	//{
	//	UDTurn();
	//	UDMove();	
	//}
	//if(GEngine)
	//{
	//	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::Printf(TEXT("총 이동거리 : %f"), distance_));
	//	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::Printf(TEXT("똥싼횟수 : %d"), evcnt_));
	//}
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	timer_ += DeltaTime;

	if(GEngine && timecnt_<10)
	GEngine->AddOnScreenDebugMessage(1, 5, FColor::Red, FString::Printf(TEXT("Timer : %f"), timer_ ));

	if (timer_ >= .5f && timecnt_ < 10)
	{
		timer_ = -.5f;
		UDTurn();
		UDMove();
		timecnt_++;
	}

	if (timecnt_ == 10)
	{
		timecnt_ = 11;
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::Printf(TEXT("총 이동거리 : %f"), distance_));
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, FString::Printf(TEXT("똥싼횟수 : %d"), evcnt_));
	}
}

