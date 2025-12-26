// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputActionValue.h"



#include "MyActor.generated.h"

UCLASS()
class ASSIGNMENT_NO5_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyActor();
	virtual void UDTurn();
	virtual void UDMove();
	virtual void RandomEvent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TSubclassOf<AActor> MySpawnClass;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	double distance_ = 0;
	double totaldist_ = 0;
	int tpcnt_ = 0;
	int evcnt_ = 0;
	FVector Vec1_ = GetActorLocation();
	double timer_=0;
	int timecnt_ = 0;
};
