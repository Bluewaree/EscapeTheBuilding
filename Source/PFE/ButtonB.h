// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyPlayer.h"
#include "ButtonB.generated.h"

UCLASS()
class PFE_API AButtonB : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AButtonB();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UShapeComponent *Button;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SMButton;

	bool Ready = false;
	bool Active = false;

	int c = 0;
	AMyPlayer *bPlayer;

	void GetPlayer(AActor *Player);

	UFUNCTION()
		void TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void TriggerExit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
};
