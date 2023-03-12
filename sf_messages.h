Constant MSG_ANSWER_DEFAULT 1001;
Constant MSG_GO_CANT_GO 	1002;
! Constant MSG_UNLOCK_DEFAULT	1003;
Constant MSG_WAIT_DEFAULT	1004;
Constant MSG_YOU_HAVE_WON	1005;
Constant MSG_YOU_HAVE_DIED	1006;
Constant MSG_PUSH_STATIC	1007;
Constant MSG_PULL_STATIC	1008;
Constant MSG_TURN_STATIC	1009;
Constant MSG_TAKE_STATIC	1010;
Constant MSG_TAKE_SCENERY	1011;
Constant MSG_SEARCH_NOTHING_SPECIAL 1012;
Constant MSG_PARSER_NOSUCHTHING 1013;
Constant MSG_DISROBE_NOT_WEARING 1014;
Constant MSG_JUMP			1015;
Constant MSG_JUMP_OVER		1016;
Constant MSG_SEARCH_NOTHING_ON	1017;
Constant MSG_PARSER_UNKNOWN_VERB		1018;
Constant MSG_SING_DEFAULT	1019;
Constant MSG_LISTEN_DEFAULT	1020;
Constant MSG_SHOUT_DEFAULT	1021;
! Constant MSG_LOCK_KEY_DOESNT_FIT	1022;
! Constant MSG_UNLOCK_KEY_DOESNT_FIT	1023;
Constant MSG_ATTACK_DEFAULT	1024;
Constant MSG_PARSER_DONT_UNDERSTAND_WORD	1025;
Constant MSG_SEARCH_ON_IT_ISARE	1026;
Constant MSG_RUB_DEFAULT	1027;
Constant MSG_SMELL_DEFAULT	1028;
Constant MSG_TAKE_ALREADY_HAVE	1029;
Constant MSG_TURN_ANIMATE	1030;
Constant MSG_CUT_NO_USE	1031;
Constant MSG_PUTON_ITSELF	1032;
Constant MSG_PUSH_SCENERY	1033;
Constant MSG_PULL_SCENERY	1034;
Constant MSG_TURN_SCENERY	1035;
Constant MSG_TAKE_ANIMATE	1036;
Constant MSG_STRONG_DEFAULT	1037;

[ CantGoMessage;
	if (parent(actor) == Ocean)
		"Nothing but the vast expanse of the ocean lies that way and this is no time for a swim.";	
	"Examining the wall you discern no sign of a passage in that direction, hidden or otherwise.";
];

[LibraryMessages p_msg p_arg_1 p_arg_2;
	p_arg_1 = p_arg_2;
	switch(p_msg) {
		MSG_ANSWER_DEFAULT:
			"~Getting static here, commander. Be advised.~";
		MSG_GO_CANT_GO:
			CantGoMessage();
		! MSG_UNLOCK_DEFAULT:
		! 	if (real_location ~= stall) {
		! 		"The multitool makes quick work of picking open ", (the)noun, ". It's now unlocked.";
		! 	} else {
		! 		"You unlock the stall door.";
		! 	}
		MSG_WAIT_DEFAULT:
			"You silently assess the situation.";
		MSG_YOU_HAVE_WON:
			print "You have won!  (good ending)";
		MSG_YOU_HAVE_DIED:
			print "You've been captured!";
		MSG_PUSH_STATIC,
		MSG_PULL_STATIC,
		MSG_TURN_STATIC,
		MSG_TAKE_STATIC:
			"You recall the commander's words, ~Leave no trace we were here,~ and decide not to tamper with anything not strictly mission-related.";
		MSG_PUSH_SCENERY,
		MSG_PULL_SCENERY,
		MSG_TURN_SCENERY,
		MSG_TAKE_SCENERY:
			"That's not going to advance your mission objective, soldier.";
		MSG_SEARCH_ON_IT_ISARE,
		MSG_SEARCH_NOTHING_ON,
		MSG_SEARCH_NOTHING_SPECIAL:
			switch(random(3)) {
				1: "You move with the sharp efficiency that elite Strike Force training gave you, but discover nothing of note.";

				2: "Time is short, but it pays to be thorough. Regardless, your search comes up empty.";

				3: "A brief examination reveals nothing that will help your mission.";
			}
		MSG_DISROBE_NOT_WEARING:
			"Even with your intensive field training, you're just not going to be able to remove that.";
		MSG_PARSER_NOSUCHTHING:
			switch(random(4)){
				1: "Strike Force training gives you the mental discipline to recognize that won't be useful on this mission.";
				
				2: "You glance at it, quickly judging it non-mission critical.";

				3: "You note its presence, but can tell from experience it won't come into play on this mission.";

				4: "You trust your battle-tested Strike Force instincts and determine that's not important for today's mission.";
			}
		! MSG_LOCK_KEY_DOESNT_FIT, MSG_UNLOCK_KEY_DOESNT_FIT:
		! 	"The multitool isn't up to the task of picking complex electronic locks.";
		MSG_JUMP, 
		MSG_JUMP_OVER:
			"The urge to hone your Strike Force-caliber physique is admirable, but you're already in peak performance for this mission.";
		MSG_SING_DEFAULT:
			"That's better left to Strike Force's media specialist, Vox.";
		MSG_KISS_DEFAULT:
			"You're risking the mission, your reputation, your friendship, and possibly a court martial with that behavior.";
		MSG_SHOUT_DEFAULT, 
		MSG_PARSER_UNKNOWN_VERB:
			"There are much more mission-critical things to do than that. Stay frosty, soldier!";
		MSG_LISTEN_DEFAULT:
			"A muffled feeling, as of being in a submarine, with the occasional light creaking of the hull under huge atmospheric pressure.";
		MSG_ATTACK_DEFAULT:
			"This is a stealth mission, not an assault. You need to keep a low profile.";
		MSG_PARSER_DONT_UNDERSTAND_WORD:
			"Your Strike Force intuition says you should find something else to focus your attentions on.";
		MSG_RUB_DEFAULT:
			"That's a job best left for The Viper.";
		MSG_SMELL_DEFAULT:
			"A little musty with an everpresent briny scent, but not nearly as foul as you would expect with a group of soldiers living in close quarters under the sea. Perhaps their research requires good air filtration?";
		MSG_TAKE_ALREADY_HAVE:
			"You fidget with ", (the)noun, ", verifying it is still on your person. It is.";
		MSG_TURN_ANIMATE:
			"Your multitool is designed to work with screws, not soldiers.";
		MSG_CUT_NO_USE:
			"You recall that HAVOC's latest plans forced you to postpone your annual mental health assessment with Dr. Grace. Keep it together until then, soldier.";
		MSG_PUTON_ITSELF:
			"Haphazardly moving things around could alert HAVOC that you were here. Better to leave that alone and maintain a minimal footprint.";
		MSG_TAKE_ANIMATE:
			"Not without filing Form 11-J2, ~Authorization to Carry a Fellow Officer~ first.";
		MSG_STRONG_DEFAULT:
			if ((player == snowdrift) && (fake_raven in real_location)) {
				"Raven shoots you an intense glare, ~We'll discuss the terms of your disciplinary measures when we're back on base.~";
			} else if ((player == raven) && (fake_snowdrift in real_location)) {
				"You mutter a swear then check to see if Snowdrift heard you. Judging from his flushed cheeks and wide eyes, he did. Major Vanguard will definitely have words for you later.";
			} else {
				"To be a Striker means discipline of the mind as well as the body. Keeping your baser emotions in check on a mission is critical to its success!";
			}
	}
];

[ DeathMessage;
	switch (deadflag) {
		3: print "Klaxons sound and spotlights activate; HAVOC has you in their clutches!";

		4: print "HAVOC forces take you and Raven into immediate custody.";

		5: print "HAVOC personnel jump to immediate attention, swarming every corner of the base.";

		6: print "Have you won?  (bad ending)";

		7: print "Complete Mission Failure!";

	}
];