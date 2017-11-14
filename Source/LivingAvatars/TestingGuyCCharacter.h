// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include <iostream>
#include <fstream>
#include "CoreMinimal.h"
#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TestingGuyCCharacter.generated.h"

UCLASS()
class LIVINGAVATARS_API ATestingGuyCCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATestingGuyCCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform scenePos;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform Hip;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform Spine;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform Spine1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform Spine2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform Neck;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform Head;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform LShoulder;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform LArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform LForeArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform LHandTrack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform RShoulder;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform RArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform RForeArm;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform RHandTrack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform LUpLeg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform LLeg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform LFoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform RUpLeg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform RLeg;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = BoneTransforms)
		FTransform RFoot;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void CalcMotionCap();

	
};
