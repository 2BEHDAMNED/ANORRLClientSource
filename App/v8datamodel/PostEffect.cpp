/*
	Written by grace - 2026 la la la la
*/

#include "stdafx.h"

#include "./v8datamodel/PostEffect.h"

const char* const ARL::sPostEffect = "PostEffect";

using namespace ARL;

REFLECTION_BEGIN();
const Reflection::PropDescriptor<PostEffect, bool> prop_Enabled("Enabled", category_State, &PostEffect::isEnabled, &PostEffect::setIsEnabled, Reflection::PropertyDescriptor::STANDARD_NO_REPLICATE);
const Reflection::PropDescriptor<BlurEffect, float> prop_Size("Size", category_State, &BlurEffect::getSize, &BlurEffect::setSize, Reflection::PropertyDescriptor::STANDARD_NO_REPLICATE);

const Reflection::PropDescriptor<ColorCorrectionEffect, float> prop_Brightness("Brightness", category_State, &ColorCorrectionEffect::getBrightness, &ColorCorrectionEffect::setBrightness, Reflection::PropertyDescriptor::STANDARD_NO_REPLICATE);
const Reflection::PropDescriptor<ColorCorrectionEffect, float> prop_Contrast("Contrast", category_State, &ColorCorrectionEffect::getContrast, &ColorCorrectionEffect::setContrast, Reflection::PropertyDescriptor::STANDARD_NO_REPLICATE);
const Reflection::PropDescriptor<ColorCorrectionEffect, float> prop_Saturation("Saturation", category_State, &ColorCorrectionEffect::getSaturation, &ColorCorrectionEffect::setSaturation, Reflection::PropertyDescriptor::STANDARD_NO_REPLICATE);
const Reflection::PropDescriptor<ColorCorrectionEffect, G3D::Color3> prop_TintColor("TintColor", category_State, &ColorCorrectionEffect::getTintColor, &ColorCorrectionEffect::setTintColor, Reflection::PropertyDescriptor::STANDARD_NO_REPLICATE);
REFLECTION_END();

PostEffect::PostEffect()
	:enabled(true)
{
	setName("PostEffect");
}

void PostEffect::setIsEnabled(bool value)
{
	if (value != enabled)
	{
		enabled = value;
		raisePropertyChanged(prop_Enabled);
	}
}

const char* const ARL::sBlurEffect = "BlurEffect";

BlurEffect::BlurEffect()
	:size(24)
{
	setName("Blur");
}

void BlurEffect::setSize(float value)
{
	if (value != size) {
		size = value;
		raisePropertyChanged(prop_Size);
	}
}

const char* const ARL::sColorCorrectionEffect = "ColorCorrectionEffect";

ColorCorrectionEffect::ColorCorrectionEffect() :
	brightness(0)
	,contrast(0)
	,saturation(0)
	,tintColor(Color3::white())
{
	setName("ColorCorrection");
}

void ColorCorrectionEffect::setBrightness(float value)
{
	if (value != brightness) {
		brightness = value;
		raisePropertyChanged(prop_Brightness);
	}
}

void ColorCorrectionEffect::setContrast(float value)
{
	if (value != contrast) {
		contrast = value;
		raisePropertyChanged(prop_Contrast);
	}
}

void ColorCorrectionEffect::setSaturation(float value)
{
	if (value != saturation) {
		saturation = value;
		raisePropertyChanged(prop_Saturation);
	}
}

void ColorCorrectionEffect::setTintColor(G3D::Color3 value)
{
	if (value != tintColor) {
		tintColor = value;
		raisePropertyChanged(prop_TintColor);
	}
}