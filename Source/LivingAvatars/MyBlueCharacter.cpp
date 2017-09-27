// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBlueCharacter.h"
#include "Engine.h"


// Sets default values
AMyBlueCharacter::AMyBlueCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyBlueCharacter::BeginPlay()
{
	Super::BeginPlay();
	//#if UR_BUILD_DEBUG
		if(GEngine) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("HELLO WORLD!"));
	//#endif
}

// Called every frame
void AMyBlueCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CalcMotionCap();
	//USkeletalMeshComponent mesh = Actor->FindComponentByClass<USkeletalMeshComponent>();

}

// Called to bind functionality to input
void AMyBlueCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool AMyBlueCharacter::isMoving()
{
	//if (this->GetCharacterMovement->Velocity.SizeSquared() < 5)
	//{
	//	return true;
	//}
	return false;
}

void AMyBlueCharacter::CalcMotionCap()
{
	//std::vector<USceneComponent> sceneComps;
	//FString fstring = FindComponentByClass<USceneComponent>()->GetName();
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("HELLO WORLD!"));
	for (UActorComponent *const component : GetComponents())
	{
		if (component->GetName().Equals("Scene"))
		{
			USceneComponent* temp = (USceneComponent*)component;
			scenePos = temp->GetRelativeTransform();
		}
		else if (component->GetName().Equals("HipTracker"))
		{
			USceneComponent* temp = (USceneComponent*)component;
			Hip = temp->GetRelativeTransform().Inverse();
						//Hip = temp->GetComponentTransform();
							//FQuat rotation = Hip.GetRotation();
							//FRotator theRot = rotation.Rotator();
							//theRot.Roll = theRot.Roll +90;
							//FQuat res(theRot);
							//Hip.SetRotation(res);
		}
		else if (component->GetName().Equals("Camera"))
		{
			USceneComponent* temp = (USceneComponent*)component;
			Head = temp->GetRelativeTransform();
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("HELLO, Creating Head!"));
		}
		else if (component->GetName().Equals("MotionController_l"))
		{
			USceneComponent* temp = (USceneComponent*)component;
			LHandTrack = temp->GetRelativeTransform();
			//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, TEXT("HELLO, Creating Left Hand!"));

		}
		else if (component->GetName().Equals("MotionController_r"))
		{
			USceneComponent* temp = (USceneComponent*)component;
			RHandTrack = temp->GetRelativeTransform();
		}
	}

	

	Spine; // .SetComponents(FQuat Rotation, FVector Translation, FVector Scale)
	Spine1;
	Spine2;
	Neck;
	LShoulder;
	LArm;
	LForeArm;
	RShoulder;
	RArm;
	RForeArm;
	LUpLeg;
	LLeg;
	LFoot;
	RUpLeg;
	RLeg;
	RFoot;
}