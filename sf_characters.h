Class Striker
has proper animate;

Striker raven_1 "Raven"
with	name
			'self' 'me' 'myself',
		short_name
			'yourself',
		add_to_scope
			dolphin,
		description
			"A proud, founding member of Strike Force. I'm this mission's field commander and security & information specialist. A black belt in various forms of martial arts and a fine jazz saxophonist, if I do say so myself.",
has female concealed;

Striker fake_snowdrift_1 "Snowdrift"
with
	name
		'snow' 'snowdrift',
	short_name
		"Snowdrift",
	found_in [;
		rtrue;
	],
	headlight_setting
		4,
	description 
		"Strike Force's Arctic specialist, expert on all things ice and snow. You personally recommended he be allowed to join Strike Force, seeing in him the intrepid spirit that drives all Strikers in the fight against HAVOC.",
	life [ r;
		Ask:
			switch (second) {
				'self', 'himself', 'snowdrift':
					"~Ah, gosh, what's there to say? Despite my expertise in the arctic, I like vacationing on a warm beach with a good book, listenin' to classical music, visitin' kin back in North Carolina,~ he says wistfully.";
				'strike', 'force':
					"~Gettin' to join Strike Force has been the great privilege of my career, thanks to your good word, commander. Speaking of which, my second anniversary is in a couple of days.~";
				'havoc':
					"~As much as I love being a Strike Force member, I'd give it up for good if it meant HAVOC was eliminated.~";
				'tachometer':
					r = random(10);
					"~I'm readin' ", tachometer.rpm - r, " rpm, commander.~";
				'pitometer', 'speedometer':
					pitometer.snowdrift();
					rtrue;
				'compass':
					compass.snowdrift();
					rtrue;
				'headlight', 'thumbswitch', 'switch':
					print "~Dolphin lights are ";
					switch(self.headlight_setting) {
						1: print "off";
						2: print "set to low beams";
						3: print "cranked up to high beams";
						4: print "runnin' in violet stealth mode";
						5: print "set to emergency beacon mode";
					}
					", commander.~";
				default:
					"~Commander, I appreciate you trying to involve me with such matters but our time is short. I'll be happy to train with you on whatever you think best back at home base,~ he says.";
			}
	],
	orders [;
		default:
			"Snowdrift demures, ~I'm only here as the field expert on HAVOC's research, commander. I need your expertise to get into the facility before I can be of any real use.~";
	],
has animate;