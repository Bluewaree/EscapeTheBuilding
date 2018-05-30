// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Code2.h"
#include "Door2.generated.h"

UCLASS()
class PFE_API ADoor2 : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoor2();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UShapeComponent *Door;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SMDoor;

	int c = 0;

	void GetCode(AActor *Door);

	ACode2 * Code;

	UFUNCTION()
		void TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
