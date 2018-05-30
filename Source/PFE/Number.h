// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ButtonA.h"
#include "Number.generated.h"

UCLASS()
class PFE_API ANumber : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ANumber();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UShapeComponent *Number;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SMNumber;

	int c = 0;

	void GetCode(AActor *Door);

	AButtonA * Button;

	UFUNCTION()
		void TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
