// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Code.h"
#include "Door1.generated.h"

UCLASS()
class PFE_API ADoor1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor1();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UShapeComponent *Door;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SMDoor;

	int c = 0;


	void GetCode(AActor *Door);
	
	ACode * Code;

	UFUNCTION()
		void TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
