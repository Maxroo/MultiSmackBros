// Fill out your copyright notice in the Description page of Project Settings.

#include "hurtBox.h"
#include "CharacterBase.h"


// Sets default values
AhurtBox::AhurtBox()
{


 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	
	

}

// Called when the game starts or when spawned
void AhurtBox::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Spawned"));
	GetWorldTimerManager().SetTimer(ActiveTime, this, &AhurtBox::GetDestroyed, 0.5f, false);
	
}


void AhurtBox::OverrideDefaults(float attackDamage, float hitstun, FVector pushDirection, FVector boxExtent)
{
	damageDealt = attackDamage;
	hitStun = hitstun;
	pushVector = pushDirection;
	boxSize = boxExtent;

}

void AhurtBox::CreateBox()
{
	hurtArea = CreateDefaultSubobject<UBoxComponent>(TEXT("HBox"));
	hurtArea->SetBoxExtent(boxSize);
	hurtArea->SetHiddenInGame(false);
	hurtArea->SetVisibility(true);
	hurtArea->bGenerateOverlapEvents = true;
	hurtArea->OnComponentBeginOverlap.AddDynamic(this, &AhurtBox::BeginOverlap);
}




// Called every frame
void AhurtBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AhurtBox::GetDestroyed() 
{
	Cast<ACharacterBase>(GetInstigator())->StartRecovery(Cast<ACharacterBase>(GetInstigator())->neutralRecovery);
	this->Destroy();
}



void AhurtBox::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult) 
{
	if(OtherActor != GetInstigator() && Cast<ACharacterBase>(OtherActor) != NULL)
	{
		Cast<ACharacterBase>(OtherActor)->GetDamaged(damageDealt, GetInstigator()->GetActorLocation(), pushVector, hitStun);
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Purple, TEXT("Colided"));
	}

}
