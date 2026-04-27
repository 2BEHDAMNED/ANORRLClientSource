#include "stdafx.h"

#include "Util/LegacyContentTable.h"
#include <boost/algorithm/string/predicate.hpp>

FASTFLAGVARIABLE(DebugRenderDownloadAssets, false)

namespace
{
	inline bool isSlash(char ch)
	{
		return ch == '\\' || ch == '/';
	}
	
	void normalizeUrl(std::string& url)
	{
		char* data = &url[0];
		size_t size = url.size();
		size_t write = 0;
		
		for (size_t i = 0; i < size; ++i)
		{
			// that's faster than tolower
			if (static_cast<unsigned int>(data[i] - 'A') < 26)
				data[write++] = (data[i] - 'A') + 'a';
			else if (isSlash(data[i]))
			{
				data[write++] = '/';
				
				// skip subsequent slashes
				while (i + 1 < size && isSlash(data[i + 1])) i++;
			}
			else
				data[write++] = data[i];
		}
		
		url.resize(write);
	}
}

namespace ARL
{
	LegacyContentTable::LegacyContentTable()
	{
		AddEntry("rbxasset://textures/A_Key_dn.png",				  "12222317");
		AddEntry("rbxasset://textures/A_Key.png",					  "12222308");
		AddEntry("rbxasset://textures/BaseballCapRed.png",			  "12222323");
		AddEntry("rbxasset://textures/bombtex.png",					  "12222348");
		AddEntry("rbxasset://textures/Bomb.png",					  "12222334");
		AddEntry("rbxasset://textures/CameraPanRight_ovr.png",		  "12222439");
		AddEntry("rbxasset://textures/CameraPanRight_dn.png",		  "12222430");
		AddEntry("rbxasset://textures/CameraPanRight.png",			  "12222420");
		AddEntry("rbxasset://textures/CameraPanLeft_ovr.png",		  "12222414");
		AddEntry("rbxasset://textures/CameraPanLeft_dn.png",		  "12222403");
		AddEntry("rbxasset://textures/CameraPanLeft.png",			  "12222388");
		AddEntry("rbxasset://textures/CameraCenter_ovr.png",		  "12222373");
		AddEntry("rbxasset://textures/CameraCenter_ds.png",			  "12222368");
		AddEntry("rbxasset://textures/CameraCenter_dn.png",			  "12222361");
		AddEntry("rbxasset://textures/CameraCenter.png",			  "12222351");
		AddEntry("rbxasset://textures/Character.png",				  "12222542");
		AddEntry("rbxasset://textures/CloneWandTexture.png",		  "12222613");
		AddEntry("rbxasset://textures/Controller1.png",				  "12222618");
		AddEntry("rbxasset://textures/Controller1_ds.png",			  "12222651");
		AddEntry("rbxasset://textures/Controller1_dn.png",			  "12222643");
		AddEntry("rbxasset://textures/Controller1_ovr.png",			  "12222658");
		AddEntry("rbxasset://textures/Controller1Tool_dn.png",		  "12222631");
		AddEntry("rbxasset://textures/Controller1Tool.png",			  "12222625");
		AddEntry("rbxasset://textures/Controller2_ovr.png",			  "12222710");
		AddEntry("rbxasset://textures/Controller2_ds.png",			  "12222700");
		AddEntry("rbxasset://textures/Controller2_dn.png",			  "12222687");
		AddEntry("rbxasset://textures/Controller2Tool_dn.png",		  "12222685");
		AddEntry("rbxasset://textures/Controller2Tool.png",			  "12222677");
		AddEntry("rbxasset://textures/Controller2.png",				  "12222671");
		AddEntry("rbxasset://textures/ControllerAI2Tool_dn.png",	  "12222736");
		AddEntry("rbxasset://textures/ControllerAI2Tool.png",		  "12222733");
		AddEntry("rbxasset://textures/ControllerAI1Tool_dn.png",	  "12222726");
		AddEntry("rbxasset://textures/ControllerAI1Tool.png",		  "12222720");
		AddEntry("rbxasset://textures/ControllerPanel.png",			  "12222767");
		AddEntry("rbxasset://textures/ControllerNoneTool_dn.png",	  "12222755");
		AddEntry("rbxasset://textures/ControllerNoneTool.png",		  "12222742");
		AddEntry("rbxasset://textures/D_Key_dn.png",				  "12222831");
		AddEntry("rbxasset://textures/D_Key.png",					  "12222825");
		AddEntry("rbxasset://textures/Down_key_dn.png",				  "12222788");
		AddEntry("rbxasset://textures/Down_key.png",				  "12222782");
		AddEntry("rbxasset://textures/Detonator.png",				  "12222773");
		AddEntry("rbxasset://textures/DropperTool_dn.png",			  "12222819");
		AddEntry("rbxasset://textures/DropperTool.png",				  "12222808");
		AddEntry("rbxasset://textures/DropperCursor.png",			  "12222805");
		AddEntry("rbxasset://textures/FireWand.png",				  "12222892");
		AddEntry("rbxasset://textures/FillTool_dn.png",				  "12222881");
		AddEntry("rbxasset://textures/FillTool.png",				  "12222872");
		AddEntry("rbxasset://textures/FlatTool_dn.png",				  "12223363");
		AddEntry("rbxasset://textures/FlatTool.png",				  "12223332");
		AddEntry("rbxasset://textures/Flamethrower.png",			  "12222937");
		AddEntry("rbxasset://textures/Gun.png",						  "12223438");
		AddEntry("rbxasset://textures/GlueCursor.png",				  "12223406");
		AddEntry("rbxasset://textures/Glue.png",					  "12223401");
		AddEntry("rbxasset://textures/HalloweenSkull.png",			  "12223869");
		AddEntry("rbxasset://textures/HalloweenRocket.png",			  "12223859");
		AddEntry("rbxasset://textures/HalloweenPumpkin.png",		  "12223503");
		AddEntry("rbxasset://textures/HalloweenGhost.png",			  "12223487");
		AddEntry("rbxasset://textures/HalloweenAsylum.png",			  "12223472");
		AddEntry("rbxasset://textures/Hammer.png",					  "12223874");
		AddEntry("rbxasset://textures/hammertex128.png",			  "12223896");
		AddEntry("rbxasset://textures/HopperPanel.png",				  "12229455");
		AddEntry("rbxasset://textures/H_Key_dn.png",				  "12223925");
		AddEntry("rbxasset://textures/H_Key.png",					  "12223920");
		AddEntry("rbxasset://textures/J_Key_dn.png",				  "12223934");
		AddEntry("rbxasset://textures/J_Key.png",					  "12229462");
		AddEntry("rbxasset://textures/K_Key_dn.png",				  "12223944");
		AddEntry("rbxasset://textures/K_Key.png",					  "12223938");
		AddEntry("rbxasset://textures/Laser.png",					  "12223948");
		AddEntry("rbxasset://textures/Left_key_dn.png",				  "12223985");
		AddEntry("rbxasset://textures/Left_key.png",				  "12223979");
		AddEntry("rbxasset://textures/LeftMotorTool_dn.png",		  "12223977");
		AddEntry("rbxasset://textures/LeftMotorTool.png",			  "12223968");
		AddEntry("rbxasset://textures/LeftMotorFastTool_dn.png",	  "12223964");
		AddEntry("rbxasset://textures/LeftMotorFastTool.png",		  "12223954");
		AddEntry("rbxasset://textures/MedKit.png",					  "12223996");
		AddEntry("rbxasset://textures/Multirocket.png",				  "12224010");
		AddEntry("rbxasset://textures/MultiSelection.png",			  "12224012");
		AddEntry("rbxasset://textures/PaintballGunTex128.png",		  "12224033");
		AddEntry("rbxasset://textures/PaintballIcon.png",			  "12229471");
		AddEntry("rbxasset://textures/pirate.png",					  "12229478");
		AddEntry("rbxasset://textures/PoliceCap.png",				  "12224039");
		AddEntry("rbxasset://textures/Right_key_dn.png",			  "12224062");
		AddEntry("rbxasset://textures/Right_key.png",				  "12224057");
		AddEntry("rbxasset://textures/Rocket.png",					  "17598704");
		AddEntry("rbxasset://textures/RocketBoots.png",				  "11900767");
		AddEntry("rbxasset://textures/rocketlaunchertex.png",		  "12224070");
		AddEntry("rbxasset://textures/S_Key_dn.png",				  "12224227");
		AddEntry("rbxasset://textures/S_Key.png",					  "12224224");
		AddEntry("rbxasset://textures/SlingshotTexture.png",		  "12224131");
		AddEntry("rbxasset://textures/Slingshot.png",				  "12224122");
		AddEntry("rbxasset://textures/Snowball.png",				  "12224133");
		AddEntry("rbxasset://textures/Snowflake.png",				  "12224137");
		AddEntry("rbxasset://textures/sombrero.png",				  "12224141");
		AddEntry("rbxasset://textures/Superball.png",				  "12224172");
		AddEntry("rbxasset://textures/SurfacePanel.png",			  "12224175");
		AddEntry("rbxasset://textures/SwordTexture.png",			  "12224218");
		AddEntry("rbxasset://textures/Sword128.png",				  "12224215");
		AddEntry("rbxasset://textures/test_texture.JPG",			  "12224240");
		AddEntry("rbxasset://textures/test2_texture.JPG",			  "12224234");
		AddEntry("rbxasset://textures/TopHatPurple.png",			  "12229488");
		AddEntry("rbxasset://textures/treetex.png",					  "12224246");
		AddEntry("rbxasset://textures/TrowelTexture.png",			  "12229499");
		AddEntry("rbxasset://textures/U_Key_dn.png",				  "12224281");
		AddEntry("rbxasset://textures/U_Key.png",					  "12224274");
		AddEntry("rbxasset://textures/Up_key_dn.png",				  "12224267");
		AddEntry("rbxasset://textures/Up_key.png",					  "12224262");
		AddEntry("rbxasset://textures/VelocityTool_ovr.png",		  "12224309");
		AddEntry("rbxasset://textures/VelocityTool_dn.png",			  "12224289");
		AddEntry("rbxasset://textures/VelocityTool.png",			  "12224285");
		AddEntry("rbxasset://textures/VelocityTool_ds.png",			  "12229500");
		AddEntry("rbxasset://textures/viking.png",					  "12224312");
		AddEntry("rbxasset://textures/W_Key_dn.png",                  "12224353");
		AddEntry("rbxasset://textures/W_Key.png",					  "12224347");
		AddEntry("rbxasset://textures/Wall.png",					  "12224320");
		
		AddEntry("rbxasset://sounds/Rocket whoosh 01.wav",			  "12222095");
		AddEntry("rbxasset://sounds/paintball.wav",					  "11900833");
		AddEntry("rbxasset://sounds/Short spring sound.wav",		  "12222124");
		AddEntry("rbxasset://sounds/Rocket shot.wav",				  "12222084");
		AddEntry("rbxasset://sounds/glassbreak.wav",				  "12222005");
		AddEntry("rbxasset://sounds/Launching rocket.wav",			  "12222065");
		AddEntry("rbxasset://sounds/Shoulder fired rocket.wav",		  "12222132");
		AddEntry("rbxasset://sounds/HalloweenThunder.wav",			  "12222030");
		AddEntry("rbxasset://sounds/HalloweenLightning.wav",		  "12222019");
		AddEntry("rbxasset://sounds/HalloweenGhost.wav",			  "12229501");
		


		AddEntry("rbxasset://icons/surface_ds.png",		"23576067");
		AddEntry("rbxasset://icons/surface.png",		"23576066");
		AddEntry("rbxasset://icons/rotate.png",			"23576065");
		AddEntry("rbxasset://icons/color_sel.png",		"23576064");
		AddEntry("rbxasset://icons/color.png",			"23576062");
		AddEntry("rbxasset://icons/insert.png",			"23576057");
		AddEntry("rbxasset://icons/freemove_ovr.png",	"23576055");	
		AddEntry("rbxasset://icons/surface_sel.png",	"23575961");	
		AddEntry("rbxasset://icons/surface_ovr.png",	"23575960");	
		AddEntry("rbxasset://icons/rotate_ovr.png",		"23575949");
		AddEntry("rbxasset://icons/rotate_ds.png",		"23575946");
		AddEntry("rbxasset://icons/resize_sel.png",		"23575942");
		AddEntry("rbxasset://icons/resize_ovr.png",		"23575941");
		AddEntry("rbxasset://icons/resize_ds.png",		"23575940");
		AddEntry("rbxasset://icons/resize.png",			"23575937");
		AddEntry("rbxasset://icons/color_ovr.png",		"23575933");
		AddEntry("rbxasset://icons/color_ds.png",		"23575928");
		AddEntry("rbxasset://icons/material_sel.png",	"23575919");	
		AddEntry("rbxasset://icons/material_ovr.png",	"23575918");	
		AddEntry("rbxasset://icons/material_ds.png",	"23575917");	
		AddEntry("rbxasset://icons/material.png",		"23575916");
		AddEntry("rbxasset://icons/lock_sel.png",		"23575914");
		AddEntry("rbxasset://icons/lock_ovr.png",		"23575912");
		AddEntry("rbxasset://icons/lock_ds.png",		"23575909");
		AddEntry("rbxasset://icons/lock.png",			"23575908");
		AddEntry("rbxasset://icons/insert_sel.png",		"23575907");
		AddEntry("rbxasset://icons/insert_ovr.png",		"23575906");
		AddEntry("rbxasset://icons/insert_ds.png",		"23575905");
		AddEntry("rbxasset://icons/freemove_sel.png",	"23575901");	
		AddEntry("rbxasset://icons/freemove_ds.png",	"23575889");	
		AddEntry("rbxasset://icons/freemove.png",		"23575887");
		AddEntry("rbxasset://icons/delete_sel.png",		"23575885");
		AddEntry("rbxasset://icons/delete_ovr.png",		"23575884");
		AddEntry("rbxasset://icons/delete_ds.png",		"23575883");
		AddEntry("rbxasset://icons/delete.png",			"23575880");
		AddEntry("rbxasset://icons/configure_sel.png",	"23575879");	
		AddEntry("rbxasset://icons/configure_ovr.png",	"23575878");	
		AddEntry("rbxasset://icons/configure_ds.png",	"23575877");	
		AddEntry("rbxasset://icons/configure.png",		"23575875");
		AddEntry("rbxasset://icons/axismove_sel.png",	"23575874");	
		AddEntry("rbxasset://icons/axismove_ovr.png",	"23575873");	
		AddEntry("rbxasset://icons/axismove_ds.png",	"23575872");	
		AddEntry("rbxasset://icons/axismove.png",		"23575871");
		AddEntry("rbxasset://icons/anchor_sel.png",		"23575870");
		AddEntry("rbxasset://icons/anchor_ovr.png",		"23575869");
		AddEntry("rbxasset://icons/anchor_ds.png",		"23575867");
		AddEntry("rbxasset://icons/anchor.png",			"23575866");

		AddEntry("rbxasset://icons/surface_dn.png",		"23629198"); 
		AddEntry("rbxasset://icons/rotate_dn.png",		"23629197"); 
		AddEntry("rbxasset://icons/resize_dn.png",		"23629194"); 
		AddEntry("rbxasset://icons/color_dn.png",		"23629193"); 
		AddEntry("rbxasset://icons/material_dn.png",	"23629192"); 
		AddEntry("rbxasset://icons/lock_dn.png",		"23629189"); 
		AddEntry("rbxasset://icons/insert_dn.png",		"23629186"); 
		AddEntry("rbxasset://icons/freemove_dn.png",	"23629182"); 
		AddEntry("rbxasset://icons/delete_dn.png",		"23629179"); 
		AddEntry("rbxasset://icons/configure_dn.png",	"23629177"); 
		AddEntry("rbxasset://icons/axismove_dn.png",	"23629176"); 
		AddEntry("rbxasset://icons/anchor_dn.png",		"23629212"); 
		
		AddEntry("rbxasset://fonts/BaseballCap.mesh",				  "12220916");
		AddEntry("rbxasset://fonts/clonewand.mesh",					  "12221344");
		AddEntry("rbxasset://fonts/fusedgirl.mesh",					  "12221423");
		AddEntry("rbxasset://fonts/girlhair.mesh",					  "12221431");
		AddEntry("rbxasset://fonts/hammer.mesh",					  "12221451");
		AddEntry("rbxasset://fonts/NinjaMask.mesh",					  "12221524");
		AddEntry("rbxasset://fonts/paintballgun.mesh",				  "11900867");
		AddEntry("rbxasset://fonts/pawn.mesh",						  "12221585");
		AddEntry("rbxasset://fonts/PirateHat.mesh",					  "12221595");
		AddEntry("rbxasset://fonts/PoliceCap.mesh",					  "12221603");
		AddEntry("rbxasset://fonts/rocketlauncher.mesh",			  "12221651");
		AddEntry("rbxasset://fonts/slingshot.mesh",					  "12221682");
		AddEntry("rbxasset://fonts/sombrero.mesh",					  "12221705");
		AddEntry("rbxasset://fonts/sword.mesh",						  "12221720");
		AddEntry("rbxasset://fonts/timebomb.mesh",					  "12221733");
		AddEntry("rbxasset://fonts/tophat.mesh",					  "12221750");
		AddEntry("rbxasset://fonts/tree.mesh",						  "12221787");
		AddEntry("rbxasset://fonts/trowel.mesh",					  "12221793");
		AddEntry("rbxasset://fonts/VikingHelmet.mesh",                "12221815");														
		
		AddEntry("rbxasset://sounds/bass.wav", "rbxasset://sounds/bass.mp3");
		AddEntry("rbxasset://sounds/button.wav", "rbxasset://sounds/button.mp3");
		AddEntry("rbxasset://sounds/clickfast.wav", "rbxasset://sounds/clickfast.mp3");
		AddEntry("rbxasset://sounds/collide.wav", "rbxasset://sounds/collide.mp3");
		AddEntry("rbxasset://sounds/electronicpingshort.wav", "rbxasset://sounds/electronicpingshort.mp3");
		AddEntry("rbxasset://sounds/flashbulb.wav", "rbxasset://sounds/flashbulb.mp3");
		AddEntry("rbxasset://sounds/grass.ogg", "rbxasset://sounds/grass.mp3");
		AddEntry("rbxasset://sounds/grass2.ogg", "rbxasset://sounds/grass2.mp3");
		AddEntry("rbxasset://sounds/grass3.ogg", "rbxasset://sounds/grass3.mp3");
		AddEntry("rbxasset://sounds/grassstone.ogg", "rbxasset://sounds/grassstone.mp3");
		AddEntry("rbxasset://sounds/grassstone2.ogg", "rbxasset://sounds/grassstone2.mp3");
		AddEntry("rbxasset://sounds/grassstone3.ogg", "rbxasset://sounds/grassstone3.mp3");
		AddEntry("rbxasset://sounds/hit.wav", "rbxasset://sounds/hit.mp3");
		AddEntry("rbxasset://sounds/ice.ogg", "rbxasset://sounds/ice.mp3");
		AddEntry("rbxasset://sounds/ice2.ogg", "rbxasset://sounds/ice2.mp3");
		AddEntry("rbxasset://sounds/ice3.ogg", "rbxasset://sounds/ice3.mp3");
		AddEntry("rbxasset://sounds/icegrass.ogg", "rbxasset://sounds/icegrass.mp3");
		AddEntry("rbxasset://sounds/icegrass2.ogg", "rbxasset://sounds/icegrass2.mp3");
		AddEntry("rbxasset://sounds/icegrass3.ogg", "rbxasset://sounds/icegrass3.mp3");
		AddEntry("rbxasset://sounds/icemetal.ogg", "rbxasset://sounds/icemetal.mp3");
		AddEntry("rbxasset://sounds/icemetal2.ogg", "rbxasset://sounds/icemetal2.mp3");
		AddEntry("rbxasset://sounds/icemetal3.ogg", "rbxasset://sounds/icemetal3.mp3");
		AddEntry("rbxasset://sounds/icestone.ogg", "rbxasset://sounds/icestone.mp3");
		AddEntry("rbxasset://sounds/icestone2.ogg", "rbxasset://sounds/icestone2.mp3");
		AddEntry("rbxasset://sounds/icestone3.ogg", "rbxasset://sounds/icestone3.mp3");
		AddEntry("rbxasset://sounds/Kerplunk.wav", "rbxasset://sounds/Kerplunk.mp3");
		AddEntry("rbxasset://sounds/Kid", "rbxasset://sounds/Kid");
		AddEntry("rbxasset://sounds/metal.ogg", "rbxasset://sounds/metal.mp3");
		AddEntry("rbxasset://sounds/metal2.ogg", "rbxasset://sounds/metal2.mp3");
		AddEntry("rbxasset://sounds/metal3.ogg", "rbxasset://sounds/metal3.mp3");
		AddEntry("rbxasset://sounds/metalgrass.ogg", "rbxasset://sounds/metalgrass.mp3");
		AddEntry("rbxasset://sounds/metalgrass2.ogg", "rbxasset://sounds/metalgrass2.mp3");
		AddEntry("rbxasset://sounds/metalgrass3.ogg", "rbxasset://sounds/metalgrass3.mp3");
		AddEntry("rbxasset://sounds/metalstone.ogg", "rbxasset://sounds/metalstone.mp3");
		AddEntry("rbxasset://sounds/metalstone2.ogg", "rbxasset://sounds/metalstone2.mp3");
		AddEntry("rbxasset://sounds/metalstone3.ogg", "rbxasset://sounds/metalstone3.mp3");
		AddEntry("rbxasset://sounds/pageturn.wav", "rbxasset://sounds/pageturn.mp3");
		AddEntry("rbxasset://sounds/plasticgrass.ogg", "rbxasset://sounds/plasticgrass.mp3");
		AddEntry("rbxasset://sounds/plasticgrass2.ogg", "rbxasset://sounds/plasticgrass2.mp3");
		AddEntry("rbxasset://sounds/plasticgrass3.ogg", "rbxasset://sounds/plasticgrass3.mp3");
		AddEntry("rbxasset://sounds/plasticice.ogg", "rbxasset://sounds/plasticice.mp3");
		AddEntry("rbxasset://sounds/plasticice2.ogg", "rbxasset://sounds/plasticice2.mp3");
		AddEntry("rbxasset://sounds/plasticice3.ogg", "rbxasset://sounds/plasticice3.mp3");
		AddEntry("rbxasset://sounds/plasticmetal.ogg", "rbxasset://sounds/plasticmetal.mp3");
		AddEntry("rbxasset://sounds/plasticmetal2.ogg", "rbxasset://sounds/plasticmetal2.mp3");
		AddEntry("rbxasset://sounds/plasticmetal3.ogg", "rbxasset://sounds/plasticmetal3.mp3");
		AddEntry("rbxasset://sounds/plasticplastic.ogg", "rbxasset://sounds/plasticplastic.mp3");
		AddEntry("rbxasset://sounds/plasticplastic2.ogg", "rbxasset://sounds/plasticplastic2.mp3");
		AddEntry("rbxasset://sounds/plasticplastic3.ogg", "rbxasset://sounds/plasticplastic3.mp3");
		AddEntry("rbxasset://sounds/plasticstone.ogg", "rbxasset://sounds/plasticstone.mp3");
		AddEntry("rbxasset://sounds/plasticstone2.ogg", "rbxasset://sounds/plasticstone2.mp3");
		AddEntry("rbxasset://sounds/plasticstone3.ogg", "rbxasset://sounds/plasticstone3.mp3");
		AddEntry("rbxasset://sounds/Rubber", "rbxasset://sounds/Rubber");
		AddEntry("rbxasset://sounds/Rubber", "rbxasset://sounds/Rubber");
		AddEntry("rbxasset://sounds/snap.wav", "rbxasset://sounds/snap.mp3");
		AddEntry("rbxasset://sounds/splat.wav", "rbxasset://sounds/splat.mp3");
		AddEntry("rbxasset://sounds/stone.ogg", "rbxasset://sounds/stone.mp3");
		AddEntry("rbxasset://sounds/stone2.ogg", "rbxasset://sounds/stone2.mp3");
		AddEntry("rbxasset://sounds/stone3.ogg", "rbxasset://sounds/stone3.mp3");
		AddEntry("rbxasset://sounds/switch.wav", "rbxasset://sounds/switch.mp3");
		AddEntry("rbxasset://sounds/SWITCH3.wav", "rbxasset://sounds/SWITCH3.mp3");
		AddEntry("rbxasset://sounds/swoosh.wav", "rbxasset://sounds/swoosh.mp3");
		AddEntry("rbxasset://sounds/swordlunge.wav", "rbxasset://sounds/swordlunge.mp3");
		AddEntry("rbxasset://sounds/swordslash.wav", "rbxasset://sounds/swordslash.mp3");
		AddEntry("rbxasset://sounds/unsheath.wav", "rbxasset://sounds/unsheath.mp3");
		AddEntry("rbxasset://sounds/uuhhh.wav", "rbxasset://sounds/uuhhh.mp3");
		AddEntry("rbxasset://sounds/victory.wav", "rbxasset://sounds/victory.mp3");
		AddEntry("rbxasset://sounds/woodgrass.ogg", "rbxasset://sounds/woodgrass.mp3");
		AddEntry("rbxasset://sounds/woodgrass2.ogg", "rbxasset://sounds/woodgrass2.mp3");
		AddEntry("rbxasset://sounds/woodgrass3.ogg", "rbxasset://sounds/woodgrass3.mp3");
		AddEntry("rbxasset://sounds/woodice.ogg", "rbxasset://sounds/woodice.mp3");
		AddEntry("rbxasset://sounds/woodice2.ogg", "rbxasset://sounds/woodice2.mp3");
		AddEntry("rbxasset://sounds/woodice3.ogg", "rbxasset://sounds/woodice3.mp3");
		AddEntry("rbxasset://sounds/woodmetal.ogg", "rbxasset://sounds/woodmetal.mp3");
		AddEntry("rbxasset://sounds/woodmetal2.ogg", "rbxasset://sounds/woodmetal2.mp3");
		AddEntry("rbxasset://sounds/woodmetal3.ogg", "rbxasset://sounds/woodmetal3.mp3");
		AddEntry("rbxasset://sounds/woodplastic.ogg", "rbxasset://sounds/woodplastic.mp3");
		AddEntry("rbxasset://sounds/woodplastic2.ogg", "rbxasset://sounds/woodplastic2.mp3");
		AddEntry("rbxasset://sounds/woodplastic3.ogg", "rbxasset://sounds/woodplastic3.mp3");
		AddEntry("rbxasset://sounds/woodstone.ogg", "rbxasset://sounds/woodstone.mp3");
		AddEntry("rbxasset://sounds/woodstone2.ogg", "rbxasset://sounds/woodstone2.mp3");
		AddEntry("rbxasset://sounds/woodstone3.ogg", "rbxasset://sounds/woodstone3.mp3");
		AddEntry("rbxasset://sounds/woodwood.ogg", "rbxasset://sounds/woodwood.mp3");
		AddEntry("rbxasset://sounds/woodwood2.ogg", "rbxasset://sounds/woodwood2.mp3");
		AddEntry("rbxasset://sounds/woodwood3.ogg", "rbxasset://sounds/woodwood3.mp3");

	}
	
	void LegacyContentTable::AddEntry(const std::string& path, const std::string& contentId)
	{
		std::string url = path;
		normalizeUrl(url);
		
		mMap[url] = contentId;
	}
	
	void LegacyContentTable::AddEntryProd(const std::string& path, const std::string& contentId)
	{
		std::string url = path;
		normalizeUrl(url);
		
		mMap[url] = format("http://arl.lambda.cam/asset/?id=%s", contentId.c_str());
	}
	
	const std::string& LegacyContentTable::FindEntry(const std::string& path)
	{
		std::string url = path;
		normalizeUrl(url);
		
		UrlMap::const_iterator it = mMap.find(url);
		
		return (it == mMap.end()) ? mEmpty : it->second;
	}
}
