// Copyright Yo Mama


#include "AbilitySystem/AuraAbilitySystemComponent.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	//Good place for a break point, am I right lads

	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	for (const FGameplayTag& Tag : TagContainer) {
		//TODO: Broadcast the tag to the widget controller
		const FString Msg = FString::Printf(TEXT("GE Tag amogus: %s"), *Tag.ToString());
		GEngine->AddOnScreenDebugMessage(-1, 8.f, FColor::Purple, Msg);
	}
}
