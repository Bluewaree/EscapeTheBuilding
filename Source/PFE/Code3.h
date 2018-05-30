// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyPlayer.h"
#include "Code3.generated.h"

UCLASS()
class PFE_API ACode3 : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACode3();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UShapeComponent *TCode;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* STCode;

	AMyPlayer *bPlayer;

	void SetCode();
	void GetPlayer(AActor *Player);

	bool bItem = false;

	bool Access = false;

	int c = 0;

	UFUNCTION()
		void TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void TriggerExit(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
