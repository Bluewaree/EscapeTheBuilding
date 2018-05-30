// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "ButtonB.h"
#include "Wall3.generated.h"

UCLASS()
class PFE_API AWall3 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWall3();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	AButtonB *bButton;
	void GetButton(AActor *Button);

	int c = 0;

	UShapeComponent *Wall;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* SMWall;
	
	UFUNCTION()
		void TriggerEnter(class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
