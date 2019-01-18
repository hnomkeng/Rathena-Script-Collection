function	script	instance_hide	{
.@arg = getarg(1);
	switch(.@arg){
		case 1:
			hideonnpc instance_npcname(getarg(0));
			return;
			
		case 2:
			hideoffnpc instance_npcname(getarg(0));
			return;
			
		case 3:
			disablenpc instance_npcname(getarg(0));
			return;
			
		case 4:
			enablenpc instance_npcname(getarg(0));
			return;
			
		case 5:
			hideonnpc instance_npcname(getarg(0));
			disablenpc instance_npcname(getarg(0));
			return;
	}
}

function	script	charleston_check	{
	.@initial_quest = checkquest(getarg(1));	
	if(BaseLevel < getarg(0)){
		cutin "nale01",0;
		mes "[ ^0000FFCharleston^000000 ]";
		mes "Hello, Adventurer. I'm Charleston, the initiator of the Project Independent.";
		next;
		mes "[ ^0000FFCharleston^000000 ]";
		mes "You don't seem strong enough for this task, come when you're at least ^0000FFLevel "+getarg(0)+"^000000.";
		close3;
	}
	switch(.@initial_quest){
		case -1:
			break;
			
		case 0: case 1: case 2:
			return;
	}
	cutin "nale01",0;
	mes "[ ^0000FFCharleston^000000 ]";
	mes "Hello, Adventurer. I'm Charleston, the initiator of the Project Independent.";
	next;
	mes "[ ^0000FFCharleston^000000 ]";
	mes "Currently, I'm unable to move, I'm having a problem with one of my components. Could you help me get the replacement parts from the factory?";
	next;
	if(select("Sure:I'm busy") == 2) close3;
	mes "[ ^0000FFCharleston^000000 ]";
	mes "The task won't be difficult if you're at least ^0000FFLevel "+getarg(0)+"^000000, healthy, free of any chronic disease, and not on prescription of any drugs.";
	next;
	mes "[ ^0000FFCharleston^000000 ]";
	mes "Please use the machine next to me to enter the factory. Once you're in, remain calm and follow	the instructions.";
	setquest getarg(1);
	close3;
}

function	script	cc_finish_check	{
	.@finish = checkquest(getarg(0));
	switch(.@finish){
		case -1:
			return;
		case 0: case 1:
			break;
	}
	cutin "nale01",0;
	mes "[ ^0000FFCharleston^000000 ]";
	mes "I couldn't stop it from happening or change the past. But maybe someone else can.";
	next;
	mes "[ ^0000FFCharleston^000000 ]";
	mes "I'll wait for that one person however long it takes.";
	getexp 1800000,600000;
	erasequest getarg(0);
	erasequest getarg(1);
	close3;
}

function	script	cc_cd_check	{
	.@cd = checkquest(getarg(0),PLAYTIME);
	switch(.@cd){
		case -1:
			return;
			
		case 0: case 1:
			cutin "nale01",0;
			mes "[ ^0000FFCharleston^000000 ]";
			mes "Your body is still under the effects of time travel. You won't be able to travel again at this state.";
			close3;
			
		case 2:
			erasequest getarg(0);
			break;
	}
	cutin "nale03",0;
	mes "[ ^0000FFCharleston^000000 ]";
	mes "Aren't you disappointed? Are you really going to let your effort go in vain? Because that'll be really stupid. I suggest you reconsider.";
	next;
	if(select("I'll try again if there's a chance.:I'll think again") == 2) close3;
	mes "[ ^0000FFCharleston^000000 ]";
	mes "I'm a robot. I do what I'm ordered to do, and nothing else matters.";
	next;
	mes "[ ^0000FFCharleston^000000 ]";
	mes "Ironic, isn't it? Robots are supposed to be incapable of emotions, and yet here I am, feeling regretful about the past.";
	next;
	mes "[ ^0000FFCharleston^000000 ]";
	mes "You can judge me, but you can't stop me. I'll continue to try as long as there's a chance.";
	next;
	mes "[ ^0000FFCharleston^000000 ]";
	mes "My core stopped, but I still can talk. Please help me.";
	if(checkquest(13184) > 0) erasequest 13184;
	setquest getarg(1);
	close3;
}

function	script	cc_enter_check	{
	.@cd = checkquest(getarg(0),PLAYTIME);
	.@initial_quest = checkquest(getarg(1));
	switch(.@cd){
		case -1:
			break;
			
		case 0: case 1:
			mes "- Your body is still under the effects of time travel. You won't be able to travel again at this state. -";
			end;
			
		case 2:
			mes "- The effect of the time travel is now cleared. You'll be able to enter Charleston Crisis. -";
			erasequest getarg(0);
			end;
	}
	switch(.@initial_quest){
		case -1:
			mes "You need ^0000FFCharleston's^000000 permission to use this machine.";
			end;
			
		case 0:
		case 1:
			return;
	}
}

function	script	charleston_mob	{
.@mob_set = getarg(0);
switch(.@mob_set){
	case 1:
		areamonster 'cc_map$,107,254,115,250,"Security Robot",3128,8; 
		break;
		
	case 2:
		areamonster 'cc_map$,52,231,60,227,"Security Robot",3128,8;
		break;
		
	case 3:
		areamonster 'cc_map$,21,164,30,156,"Security Robot",3128,8;
		areamonster 'cc_map$,46,87,57,78,"Security Robot",3128,8;
		break;
		
	case 4:
		areamonster 'cc_map$,85,51,95,46,"Security Robot",3128,8;
		break;
		
	case 5:
		areamonster 'cc_map$,120,29,129,26,"Security Robot",3128,8;
		areamonster 'cc_map$,226,37,249,18,"Security Robot",3128,8;
		break;
		
	case 6:
		areamonster 'cc_map$,160,57,173,50,"Security Robot",3128,8;
		areamonster 'cc_map$,188,62,199,73,"Security Robot",3128,2;
		break;
		
	case 7:
		areamonster 'cc_map$,227,202,235,192,"Security Robot",3128,8;
		areamonster 'cc_map$,272,191,291,172,"Security Robot",3128,6;
		break;
		
	case 8:
		areamonster 'cc_map$,130,233,137,235,"Security Robot",3128,6;
		areamonster 'cc_map$,174,225,207,195,"Security Robot",3128,6;
		instance_hide("charleston_warp#cc_warp_5",4);
		break;
		
	case 9:
		areamonster 'cc_map$,117,194,117,190,"Security Robot",3128,8;
		instance_hide("charleston_warp#cc_warp_6",4);
		instance_hide("charleston_warp#cc_warp_7",4);
		break;
		
	case 10:
		areamonster instance_mapname("1@mcd"),123,70,133,66,"--ja--",3128,8;
		break;
		
	case 20:
		monster 'cc_map$,86,231,"Hallway Security",3127,1;
		monster 'cc_map$,172,196,"Hallway Security",3127,1;
		monster 'cc_map$,126,84,"Hallway Security",3127,1;
		monster 'cc_map$,100,149,"Hallway Security",3127,1;
		monster 'cc_map$,158,149,"Hallway Security",3127,1;
		return;
		
	case 21:
		areamonster 'cc_map$,139,219,151,207,"C-TYPE",3128,6;
		areamonster 'cc_map$,139,219,151,207,"D-TYPE",3128,3;
		return;
		
	case 22:
		areamonster 'cc_map$,139,219,151,207,"L-TYPE",3128,2;
		areamonster 'cc_map$,139,219,151,207,"O-TYPE",3128,2;
		areamonster 'cc_map$,139,219,151,207,"B-TYPE",3126,1;
		return;
		
	case 23:
		areamonster 'cc_map$,139,219,151,207,"T-TYPE",3128,2;
		areamonster 'cc_map$,139,219,151,207,"O-TYPE",3128,2;
		return;
		
	case 24:
		areamonster 'cc_map$,139,219,151,207,"T-TYPE",3128,2;
		areamonster 'cc_map$,139,219,151,207,"O-TYPE",3128,2;
		areamonster 'cc_map$,139,219,151,207,"C-TYPE",3128,5;
		return;
		
	case 25:
		areamonster 'cc_map$,139,219,151,207,"C-TYPE",3128,5;
		areamonster 'cc_map$,139,219,151,207,"D-TYPE",3128,2;
		return;
	}	
	instance_hide(getarg(1),5);
	end;
}