[ SimpleUnlockSub;
	if (noun hasnt lockable)
		"There's no locking mechanism on ", (the) noun, ".";
	"There's no trivial way to unlock ", (the)noun, ". You'll need to use a tool or key to get it open.";
];

[ ToolUnlockSub;
	if (second == multitool) <<LockPick noun second>>;
	<<Unlock noun second>>;
];

Extend 'unlock' replace
	* noun -> SimpleUnlock
	* noun 'with'/'using' held -> ToolUnlock;

[ SimpleLockSub;
	if (noun hasnt lockable)
		"There's no locking mechanism on ", (the) noun, ".";
	"You'll need to use a suitable key or tool to lock ", (the)noun, ". ";
];

[ ToolLockSub;
	if (second == multitool) <<LockPick noun second>>;
	<<Lock noun second>>;
];

Extend 'lock' replace
	* noun -> SimpleLock
	* noun 'with'/'using' held -> ToolLock;

Extend only 'open' replace
	* noun                                      -> Open
	* noun 'with' held                          -> ToolUnlock;

[ ScrewSub;
	if (second){
		if (second ~= multitool) {
		"You use every skill in your considerable training to manipulate ", (the) noun, " with ", (the) second, " but it's just not possible without tool assistance.";
		}
	}
];

Extend 'turn'
	* noun 'with'/'using' noun -> Screw;
Extend 'remove' first
	* removable -> Remove
	* noun 'with'/'using' noun -> Screw;
Verb 'replace' 'loosen' 'tighten'
	* noun -> Screw
	* noun 'with'/'using' noun -> Screw;

[ AttachOrTieSub; 
	if (~~(noun ofclass Wire && second ofclass Wire))
		<<Tie noun second>>;
	"Wires can be attached to other wires, but need a solid connection to be effective.";
];

[ AttachClarifySub;
	"Your Strike Force multitool has many functions. You'll need to specify the specific function that should be used to attach those together.";
];

[ AttachSub;
	if (noun ofclass Wire && second ofclass Wire) {
		<<Solder noun second>>;
	}
	"There's no clear way to attach ", (the)noun, " to ", (the)second, ".";
];

Verb 'connect' = 'attach';
Verb 'reattach' = 'attach';
Extend 'attach' first
	* noun 'to' noun -> AttachOrTie
	* noun 'to' noun 'with'/'using'/'by' 'tool'/'multitool' -> AttachClarify
	* noun 'to' noun 'with'/'using'/'by' 'torch' -> Attach
	* noun 'to' noun 'with'/'using'/'by' 'soldering' 'multitool'/'tool'/'iron'/'torch' -> Attach;

[ SolderClarifySub;
	<<Solder noun noun>>;
];

[ SolderSub; 
	if ((noun ofclass Striker) || (second ofclass Striker))
		"Soldering soldiers suffers soldierly sneers.";
	if (~~(noun ofclass Wire) || ~~(second ofclass Wire))
		"The soldering component of the multitool is really only strong enough for light tasks, like reconnecting wires.";
	if ((noun ofclass Wire) && (second ofclass Wire)) {
		if ((noun hasnt general) || (second hasnt general))
			"Only cut wires can be soldered together.";
	} else {
		"The multitool's soldering torch is relatively weak, really only effective for wires. At any rate, soldering random objects together will only give HAVOC evidence of your incursion.";
	}
	if (noun == second) {
		give noun ~general;
		noun.crossed = nothing;
		print (The)noun, " is fused back into one wire.";
		CalculatePressure();
		"";
	}
	if (noun ~= second) {
		if (green_wire == noun or second) {
			deadflag = 3;
			"Years of field expertise scream at you to leave the green wire alone. Nevertheless you push forward with your questionable plan to tamper further with its voltage.";
		}
		noun.crossed = second;
		second.crossed = noun;
		give noun ~general;
		give second ~general;
		print "A small hyperbaric solder point lights and fuses ", (the)noun, " wire to ", (the)second, " wire with a faint electric sizzle.";
		CalculatePressure();
		"";
	}
	"UNEXPECTED: Some edge case fell through to here!";
];

Verb 'solder' 'fuse'
	* noun 'to'/'and'/'with' 'self'/'itself' -> SolderClarify
	* noun -> Solder
	* noun 'to'/'and'/'with' noun -> Solder
	* noun 'to'/'and'/'with' noun 'with'/'using'/'by' 'torch'/'tool'/'soldering'/'multitool' -> Solder
	* noun 'to'/'and'/'with' noun 'with'/'using'/'by' 'soldering' 'multitool'/'tool'/'torch'/'iron' -> Solder
	* noun 'with'/'using'/'by' 'torch'/'tool'/'multitool' 'to' noun -> Solder
	* noun 'with'/'using'/'by' 'soldering' 'iron'/'tool'/'torch'/'multitool' 'to' noun -> Solder;

[ DirectionPromptSub;
	"Something at the research facility is causing your multitool compass to behave erratically. You'll need to use nautical terms on this mission: fore (f), aft (a), port (p), and starboard (sb).";
];

Verb 'n//' 'north' 's//' 'south' 'e//' 'east' 'w//' 'west' 'nw' 'northwest' 'ne' 'northeast' 'sw' 'southwest' 'se' 'southeast'
	* -> DirectionPrompt;

[ UseExplainSub;
	"Being a member of the elite Strike Force, precision of words is as important as precision of actions.";
];

Verb 'use' 'utilize'
	* noun -> UseExplain
	* noun 'on'/'with' noun -> UseExplain;

Verb 'describe' = 'examine';

[ HelpSub;
	"Raven and Snowdrift are on their own; there's no additional help on the way.";
];

Verb 'help'
	* -> Help;

[ LockPickSub pick_diff;
	if (noun ofclass Striker)
		"Out of the box thinking is good field work, but this is a little far afield.";
	if (noun hasnt lockable)
		print_ret (The)noun, " doesn't seem to have any kind of lock.";
	if (second && second ~= multitool)
		print_ret (The) second, " isn't up to the task of picking ", (the)noun, "'s lock.";
	if (~~(noun provides pickability))
		"The lock on ", (the)noun, " is electronic and not pickable. You'll need to find a different way to open it.";
	pick_diff = player.pick_skill() - noun.pickability();
	if (pick_diff < 0)
		"A Striker more adept at lockpicking might be able to do it, but the lock proves impossible to pick at your skill level.";
	if (noun.pickability() == 0) {
		print "A laughably simple lock; you barely even needed a multitool at all.";
	} else {
		switch (pick_diff) {
			0: print "You struggle with the lockpick and silently resolve to take lessons after this mission; the lock finally gives.";
			1: print "The lock proves a considerable challenge for your current skill level, but you manage it.";
			2: print "A bit of a challenge, but your lockpicking skills are up to the task.";
			3: print "After a couple of false starts, the lock succumbs to your lockpicking prowess.";
			default: print "This lock has utterly met its match in you and your skills.";
		}
	}
	print "^";
	if (noun has locked) {
		give noun ~locked;
		print_ret (The) noun, " is now unlocked.";
	} else {
		give noun locked;
		print_ret (The) noun, " is locked up tight.";
	}
];

[ PickUpSub;
	if (second ~= tongs)
		print_ret (The) second, " isn't designed grabbing or picking things up.";
	if (noun hasnt small)
		print_ret (The) noun, " is too big for the tongs to get a grip on.";
	if (noun in tongs) 
		"That's already being held by the tongs.";
	move noun to tongs;
	update_moved = true;
	"The tongs prove well-suited to grasping small things like ", (the)noun, ".";
];

Verb 'grab' = 'take';
Verb 'extract' = 'take';
Verb 'extricate' = 'take';
Verb 'withdraw' = 'take';

Extend 'pick' last
	* noun -> LockPick
	* 'up' noun -> Take
	* noun 'with'/'using' noun -> LockPick
	* 'open' noun 'with'/'using' noun -> LockPick
	* 'up' noun 'with'/'using' noun -> PickUp;

Extend 'close' last
	* noun 'with'/'using' noun -> Close;

Extend 'take' last
	* 'out'/'a//' noun 'with'/'using' noun -> PickUp
	* noun 'with'/'using' noun -> PickUp;

[ PushWithSub;
	if (second ~= tongs) print_ret (The)second, " isn't suited to the task of pushing things around.";
];

Verb 'position' = 'push';
Verb 'reposition' = 'push';
Verb 'roll' = 'push';
Extend 'push' last
	* noun 'with'/'using' noun -> PushWith
	* noun 'next'/'adjacent'/'over' 'to'/'near' noun -> Transfer
	* noun 'beside'/'alongside'/'near' noun -> Transfer;


Extend 'look' last
	* 'out'/'outside' noun -> Examine
	* 'under'/'behind' noun -> Search;

[ DescendSub; 
	if ((noun == stepladder) || (actor in stepladder)) <<Exit noun>>;
	"There's nowhere to descend when standing on the floor.";
];

Verb 'descend'
	* -> Descend
	* noun -> Descend;

[ FlushSub;
	if (noun ~= toilet) {
		<Insert noun toilet>;
		<<Flush toilet>>;
	}
];

Verb 'flush'
	* noun -> Flush;

[ SearchLocationSub;
	<<Search real_location>>;
];

Extend 'search' first
	* -> SearchLocation
	* 'in'/'on'/'under'/'behind'/'inside' noun -> Search;

Verb 'cross' 'reverse'
	* noun 'with'/'and' noun -> AttachOrTie;

[ ShootSub;
	"There is no firearm nearby to fire. Even if there were, you'd jeopardize not just the mission but your and Raven's lives!";
];

Verb 'shoot' 'fire'
	* -> Shoot
	* noun -> Shoot;

[ HygieneSub;
	if (real_location == Showers or Latrine)
		"Even if the situation were absolutely safe, there's no way you'd be caught dead using HAVOC's hygiene products on yourself.";
	if (noun == player || noun in player)
		"There will be time for that when you get back to home base.";
	<<Rub noun>>;
];

Verb 'shave' 'brush' 'floss' 'shower' 'bathe' 'wash'
	* -> Hygiene
	* noun -> Hygiene
	* topic -> Hygiene;

Extend only 'clean' replace
	* noun -> Hygiene;

[ CutOrAttackSub;
	if (noun ofclass Wire && second == multitool)
		<<Cut noun>>;
	if (noun ofclass Striker)
		<<Cut noun>>;
	if (parent(second) == player)
		<<Attack noun second>>;
	"You'd need many more years of combat training to cut ", (an)noun, " with ", (an)second, ".";
];

Extend 'cut' first
	* noun 'with'/'using' noun ->CutOrAttack;

[ SabotageSub;
	if (noun) {
		if (noun ofclass Striker)
			"That's borderline treason, soldier.";
		"There's no such simplistic way to disable ", (the)noun,". You'll need to work out a more exact methodology.";
	}
	"You take a moment to puzzle out how to disable it, but nothing comes to mind.";
];

Verb 'disable' 'sabotage'
	* noun -> Sabotage
	* topic -> Sabotage;

[ ClimbLadderSub;
	if (stepladder in real_location) {
		if (player in stepladder) {
			if (selected_direction == d_to) {
				<<Exit stepladder>>;
			}
			if (selected_direction == u_to)
				"You're already standing on top of the stepladder.";
		} else {
			if (selected_direction == u_to) {
				<<Enter stepladder>>;
			}
		}
	} else {
		if (selected_direction == d_to)
			"You're not on top of anything from which you could climb down.";
		if (selected_direction == u_to)
			"There is nothing worth climbing around here.";
	}
	"Perhaps with advanced acrobatics training you could climb in that direction. You make a note to consult with your fitness coach after this mission.";
];

Extend 'climb' first
	* noun=ADirection -> ClimbLadder
	* 'down'/'off' noun -> Exit
	* 'down'/'off' 'off'/'of'/'from' noun -> Exit
	* 'down' 'off' 'of'/'from' noun -> Exit;

[ XyzzySub; 
	print (italic)"Strike Force continues after these messages!^^";

	switch(random(4)) {
		1:
			print "Hi, I'm Tom Selick from NBBC's ~Jaguar P.I.~ and I'd like to speak to you today about term life insurance. Many people talk a lot about preparing for the unexpected, but never actually take the time to sit down and do something about it.^^In fact, you might be one of those very people. If so, I urge you to call the good people at McMasters Brothers today. A free consultation over the phone means you can start arranging for your family's future from the comfort of your very own home. No hassles, no traffic to fight, just peace of mind. Call now at 1-800-555-3673.";
		2:
			print "You are the final starfighter, earth's last hope for survival against an alien invasion! Blast your way through waves of enemies, collect fuel, destroy the defensive shield, and detonate the Kildaxian Central Core! Can you save earth and get the highest score? Play ~Galactic Onslaught~, available now for the Sente 5200.";
		3:
			print "The battle for control of the Roboformers's home planet of Mechalor Prime has begun! The evil Omnivore disguises himself as an aircraft carrier and infiltrates the Sentinel home base. Alpha Twillix sends in air support, Jetstream and Tailwind, to intercept and drive him back. Alpha Twillix converts to her laser cannon form and delivers a devastating blow! Omnivore is defeated! For now...^^Omnivore, Alpha Twillix, Jetstream, Tailwind and the entire Roboformers line are available exclusively at Jungle Toy locations nationwide!";
		4:
			print "~Honey, what's wrong? You look pale and seem out of energy,~ a woman in a white blouse and blue skirt says, checking a man's forehead for a fever with the back of her hand.^^
			~I don't know, I thought it was just stress from work but I've been feeling,~ the man, wearing pajamas with slippers, darts his eyes left and right and whispers in embarassment, ~constipated.~^^
			His wife gives a warm smile of assurance, ~I thought that might be what's going on.~ With that, she hands him a yellow box with black lettering that reads ~Laxitol.~";
			print (italic) "^^The following day...^^";
			print "A beautiful sunny morning on an impeccibly maintained golf course. The man, dressed smartly for a round on the links, smiles as his wife hands him a driver, ~Feels good to be back in the game!~^^Laxitol is now available without a prescription at fine drugstores everywhere.";
	}

	print_ret (italic)"^^We now return to Strike Force!";
];
Verb 'xyzzy' * -> Xyzzy;