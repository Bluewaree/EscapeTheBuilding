// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyPlayer.h"
#include "ButtonA.generated.h"

UCLASS()
class PFE_API AButtonA : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AButtonA();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	int c = 0;
	int c2 = 0;
	int Click = 0;
	bool bItem = false;

	AMyPlayer *bPlayer;
	void GetPlayer(AActor *Player);

	UShapeComponent *Button;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SMButton;
	
	UFUNCTION()
		void TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void TriggerExit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};

