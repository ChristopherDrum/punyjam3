Class DeepOcean
with
	initial [;
		DeepOceanX.n_to = DeepOceanX;
		DeepOceanX.ne_to = DeepOceanX;
		DeepOceanX.e_to = DeepOceanA;
		DeepOceanX.se_to = DeepOceanX;
		DeepOceanX.s_to = DeepOceanX;
		DeepOceanX.sw_to = DeepOceanX;
		DeepOceanX.w_to = DeepOceanX;
		DeepOceanX.nw_to = DeepOceanX;
		DeepOceanX.u_to = DeepOceanX;
		DeepOceanX.d_to = DeepOceanX;
	],
	name
		'ocean' 'water' 'waters' 'deep' 'sea',
	n_to[;
		DeepOceanX.s_to = real_location;
		return DeepOceanX;
	],
	ne_to[;
		DeepOceanX.sw_to = real_location;
		return DeepOceanX;
	],
	e_to [;
		DeepOceanX.w_to = real_location;
		return DeepOceanX;
	],
	se_to[;
		DeepOceanX.nw_to = real_location;
		return DeepOceanX;
	],
	s_to[;
		DeepOceanX.n_to = real_location;
		return DeepOceanX;
	],
	sw_to[;
		DeepOceanX.ne_to = real_location;
		return DeepOceanX;
	],
	w_to [;
		DeepOceanX.e_to = real_location;
		return DeepOceanX;
	],
	nw_to[;
		DeepOceanX.se_to = real_location;
		return DeepOceanX;
	],
	u_to[;
		DeepOceanX.d_to = real_location;
		return DeepOceanX;
	],
	d_to[;
		DeepOceanX.u_to = real_location;
		return DeepOceanX;
	];

Object DeepOceanX "The Briny Deep"
with
	description
		"Devoid of light and life, just the deep blackness of vast, unknown waters; it would be all too easy to become helplessly lost.^^~Wish Fathom could'a joined us. He wouldn't have any trouble navigatin' down here,~ Snowdrift says.^^~Trust your training, soldier. We'll be alright,~ you reply, though you can't help but agree with the sentiment.",
	after [;
		Go:
			if (self.selected_direction ofclass DeepOcean)
				self.selected_direction = self;
	],
	n_to
		DeepOceanX,
	ne_to 
		DeepOceanX,
	e_to 
		DeepOceanX,
	se_to 
		DeepOceanX,
	s_to 
		DeepOceanX,
	sw_to 
		DeepOceanX,
	w_to
		DeepOceanX,
	nw_to 
		DeepOceanX,
	u_to 
		DeepOceanX,
	d_to 
		DeepOceanX;

DeepOcean DeepOceanA "A"
with
	description
		"Deep Ocean A",
	n_to
		DeepOceanB,
	s_to
		"That just leads back to the exfiltration point. You need to push forward and find HAVOC's base!";
	
DeepOcean DeepOceanB "B"
with
	description
		"Deep Ocean B",
	nw_to
		DeepOceanC,
	s_to
		DeepOceanA;

DeepOcean DeepOceanC "C"
with
	description
		"Deep Ocean C",
	se_to
		DeepOceanB,
	d_to
		DeepOceanD;

DeepOcean DeepOceanD "D"
with
	description
		"Deep Ocean D",
	u_to
		DeepOceanC,
	ne_to
		DeepOceanE;

DeepOcean DeepOceanE "E"
with
	description
		"Deep Ocean E",
	sw_to
		DeepOceanD,
	ne_to
		DeepOceanF;

DeepOcean DeepOceanF "F"
with
	description
		"Shark!",
	sw_to
		DeepOceanE;

Object deep_ocean_scenery "a steady stream of fish"
with
	name
		'stream' 'fish',
	found_in
		DeepOceanA DeepOceanB DeepOceanC DeepOceanD DeepOceanE,
	react_before [;
		Listen:
			"Just the sound of your and Snowdrift's breathing can be heard through the in-helmet communication system.";
		Smell:
			"The slight staleness of recirculated oxygen and the tuna sandwich you ate for lunch.";
	],
	description [;
		switch(real_location) {
			DeepOceanA:
				"A large school of small, silvered cod and a few pink snailfishes run headfirst against your and Snowdrift's D.O.L.P.H.N. units, unperterbed by your presence, their collective mind focused on something else. They disappear behind you to the south.";
			DeepOceanB:
				"More cod, more snailfishes, and a tailed fish, maybe a stingray, here and there flow in from the northwest and swim hurriedly away to the south.";
			DeepOceanC:
				"~Are those stingrays?~ you ask Snowdrift. ~Skates,~ he replies, ~related to stingrays and sharks.~ A healthy river of the diamond-shaped creatures flows up from below and to the southeast.";
			DeepOceanD:
				"~Something has these critters riled up,~ Snowdrift observes. ~Might have something to do with whatever HAVOC's working on,~ you note. A couple of flounder wriggle in from the northeast and a scattering of skates breaks up between you and Snowdrift into the waters above you.";
			DeepOceanE:
				"A number of flounder, well camouflaged with the silt on the oceanbed, and a few long, brown and grey sole skim the ocean floor. A couple of large halibut and salmon dart in from the northeast and disappear swiftly to the southwest.";
			DeepOceanF:
				"There are no fish to be found, just the menace of the shark bearing in on you from ahead!";
		}
	],
has scenery;

Object dolphin "D.O.L.P.H.N. unit"
with
	name
		'propulsion' 'unit' 'dolphn' 'dolphin',
	article
		"your",
	description 
		"Affectionately known as a 'dolphin' (D.O.L.P.H.N. : Deep Oceanic Lifeline and Propulsive Hydro-Navigator), this one-man propulsion unit has a glass bullet-dome front flanked by angled outlet vents. Chopper-style handles are used for steering and throttle. Other functions can be activated on the dashboard. It drags a rider through the water, like a seatless motorcycle for the sea.",
has enterable scenery;

Object dome "glass bullet-dome" dolphin
with
	name
		'glass' 'bullet-dome' 'dome' 'front',
	description
		"2cm thick tempered glass, can take quite a few direct shots from a HAVOC pistol before being compromised. This one is brand new for the mission.",
has scenery;

Object dashboard "dashboard" dolphin
with
	name
		'dashbaord' 'dash',
	description
		"D.O.L.P.H.N units are quite simple to use. The dashboard has a power switch, compass, tachometer, and pitometer.",
has scenery;

Object handles "handlebars" dolphin
with
	name
		'handle' 'handles' 'handlebars',
	description
		"Much like the handlebars of your favorite Harley, the left grip rotates for throttle and has a squeezable lever for braking. The right has a thumbswitch to toggle headlights, and a lever for manually changing gears should the automatic system fail.",
has scenery;

Object headlights "headlight thumbswitch" dolphin
with
	name
		'headlight' 'thumbswitch' 'switch',
	raven_setting
		4,
	snowdrift_setting
		4,
	description[;
		print "A 5-position switch, it's currently on setting ", self.raven_setting, ", ";
		switch(self.raven_setting){
			1: print "off.";
				if (self.snowdrift_setting == 1) "With Snowdrift's lights also off, the oppressive darkness of the water weighs down on you.";
			2: print "orange low beams.";
			3: print "white high beams.";
			4: print "violet stealth lighting.";
			5: print "red distress beacon.";
		}
		
	],
has scenery;

Object pitometer "pitometer" dolphin
with
	name
		'pitometer' 'speedometer',
	raven_speed
		20,
	snowdrift_speed [;
		return (self.raven_speed - random(3));
	],
	snowdrift [;
		"~Currently runnin' at ", self.snowdrift_speed(), " knots, commander.~";
	],
	description [;
		if (self hasnt general) {
			give self general;
			"A round gauge with demarcations from 0 to 150 knots, much like you'd find on a motorbike. It measures relative speed of the dolphin against the water speed. In 100% still water it's no different than a terrestrial speedometer.^^It reads ", self.raven_speed, " knots.";
		}
		"For all practical purposes, this is your speedometer. It reads ", self.raven_speed, " knots, with a maximum of 150.";
	],
has scenery;

Object tachometer "tachometer" dolphin
with
	name
		'tachometer',
	rpm
		1200,
	description[;
		if (self hasnt general) {
			give self general;
		"Visually similar to the pitometer, this shows the RPM of the engine on a gauge that runs 0 to 8000, and currently reads ", self.rpm, "rpm. A dolphin's gears shift automatically, so this is mostly for the operator to check if the engine is overworking.";
		}
		"Gauges the engine's current working speed in revolutions per minute. It currently reads ", self.rpm, "rpm.";
	],
has scenery;

Object compass "compass" dolphin
with
	name
		'compass',
	snowdrift
		"~I've calibrated compasses on hundreds of missions, both research and Strike Force related. They should be working, but something is interfering with their operation.~",
	description [;
		if (self hasnt general) {
			give self general;
			"You tap your compass, ~Snowdrift, is your compass also going crazy?~^^~Yes commander, it sure is. We're well above the 60th parallel right now, so that would normally be expected. But I calibrated us for this mission before we left. For the short range we're travelling we should have been fine,~ Snowdrift trails off, sounding worried.^^~Wherever HAVOC goes, chaose follows. I trust you did your best. No doubt whatever has these fish riled up is responsible for our compasses as well.~";
		}
		"Your compass is rendered useless due to some kind of local interference. Maybe HAVOC has a jamming device activated.";
	],
has scenery;