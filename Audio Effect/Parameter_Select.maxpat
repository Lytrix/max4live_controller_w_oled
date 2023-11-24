{
	"patcher" : 	{
		"fileversion" : 1,
		"appversion" : 		{
			"major" : 8,
			"minor" : 5,
			"revision" : 5,
			"architecture" : "x64",
			"modernui" : 1
		}
,
		"classnamespace" : "box",
		"rect" : [ 52.0, 105.0, 965.0, 734.0 ],
		"bglocked" : 0,
		"openinpresentation" : 1,
		"default_fontsize" : 12.0,
		"default_fontface" : 0,
		"default_fontname" : "Arial",
		"gridonopen" : 1,
		"gridsize" : [ 15.0, 15.0 ],
		"gridsnaponopen" : 1,
		"objectsnaponopen" : 1,
		"statusbarvisible" : 2,
		"toolbarvisible" : 1,
		"lefttoolbarpinned" : 0,
		"toptoolbarpinned" : 0,
		"righttoolbarpinned" : 0,
		"bottomtoolbarpinned" : 0,
		"toolbars_unpinned_last_save" : 0,
		"tallnewobj" : 0,
		"boxanimatetime" : 200,
		"enablehscroll" : 1,
		"enablevscroll" : 1,
		"devicewidth" : 0.0,
		"description" : "",
		"digest" : "",
		"tags" : "",
		"style" : "",
		"subpatcher_template" : "",
		"assistshowspatchername" : 0,
		"boxes" : [ 			{
				"box" : 				{
					"id" : "obj-45",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 1741.0, 790.0, 22.0, 22.0 ],
					"text" : "t b"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-65",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1945.0, 537.0, 109.0, 22.0 ],
					"text" : "r ----track_selected"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-48",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "" ],
					"patching_rect" : [ 951.5, 560.0, 31.0, 22.0 ],
					"text" : "t b s"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-39",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 953.5, 349.0, 53.0, 22.0 ],
					"text" : "route $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-51",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 720.0, 343.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-43",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1493.0, 986.0, 50.0, 22.0 ],
					"text" : "3252"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-24",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 753.0, 378.0, 35.0, 22.0 ],
					"text" : "del 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-127",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1873.0, 581.0, 32.0, 22.0 ],
					"text" : "gate"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-211",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 753.0, 274.623149335384369, 177.0, 47.0 ],
					"text" : "Bang once when track is selected to update offset, 1 delay to give gate time to open"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-210",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1938.177978515625, 494.467560410499573, 168.0, 33.0 ],
					"text" : "turn on in/output based on active track ableton live"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-189",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1764.0, 947.0, 101.0, 22.0 ],
					"text" : "12 0.742676"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-173",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 753.0, 426.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-166",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1474.0, 424.0, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-159",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1520.0, 417.467560410499573, 50.0, 22.0 ],
					"text" : "3042"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-141",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1513.0, 1118.0, 64.0, 22.0 ],
					"text" : "print offset"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-109",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 753.0, 325.090709745883942, 146.0, 22.0 ],
					"text" : "r ---trigger_selected_once"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-3",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 6,
					"outlettype" : [ "bang", "bang", "bang", "bang", "bang", "bang" ],
					"patching_rect" : [ 444.934070459433997, 551.198332786560059, 71.5, 22.0 ],
					"text" : "b 6"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-107",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "", "", "" ],
					"patching_rect" : [ 27.0, 352.856277167797089, 113.0, 22.0 ],
					"restore" : [ 12 ],
					"saved_object_attributes" : 					{
						"parameter_enable" : 0,
						"parameter_mappable" : 0
					}
,
					"text" : "pattr save_selected",
					"varname" : "save_selected"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-128",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 585.0, 863.0, 50.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 355.010995558330023, 7.292045831680298, 40.0, 22.0 ],
					"text" : "kHz"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-10",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 602.97253300888201, 1016.629168808460236, 75.0, 22.0 ],
					"text" : "s ---to_serial"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-155",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 315.0, 690.259999999999991, 66.0, 22.0 ],
					"text" : "unpack s s"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-154",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 394.792091339826584, 862.948126882314682, 66.0, 22.0 ],
					"text" : "unpack s s"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-134",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 379.980770915746689, 898.0, 89.62264084815979, 22.0 ],
					"text" : "FREQ"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-130",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 5,
					"outlettype" : [ "", "", "", "", "" ],
					"patching_rect" : [ 362.0, 827.937823891639709, 85.0, 22.0 ],
					"text" : "regexp (.{1\\,4})"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-115",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 362.0, 741.92537201881396, 66.0, 22.0 ],
					"text" : "toupper $1"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Lato",
					"fontsize" : 11.595186999999999,
					"id" : "obj-116",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 362.0, 785.0, 77.0, 22.0 ],
					"saved_object_attributes" : 					{
						"filename" : "struplow.js",
						"parameter_enable" : 0
					}
,
					"text" : "js struplow.js"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-125",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 319.75, 333.856277167797089, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-120",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 158.0, 273.888716757297516, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-110",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "bang", "int", "int" ],
					"patching_rect" : [ 158.0, 236.0, 83.0, 22.0 ],
					"text" : "live.thisdevice"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-123",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1181.0, 1171.759606242179871, 99.0, 33.0 ],
					"text" : "send slidervalue to display"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-122",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1181.0, 1147.759606242179871, 75.0, 22.0 ],
					"text" : "s ---to_serial"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-121",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1122.543479144573212, 1081.629168808460236, 146.456520855426788, 22.0 ],
					"text" : "/p1/slidervalue 0.742676"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-119",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1250.0, 1040.629168808460236, 53.0, 22.0 ],
					"text" : "prepend"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-98",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1122.543479144573212, 972.0, 41.0, 22.0 ],
					"text" : "set $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-99",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1122.543479144573212, 831.050860285758972, 53.0, 22.0 ],
					"text" : "/p1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-103",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1176.543479144573212, 877.0, 69.0, 22.0 ],
					"text" : "/slidervalue"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-108",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 1122.543479144573212, 934.0, 73.0, 22.0 ],
					"text" : "combine s s"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-97",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 315.0, 1040.629168808460236, 63.0, 20.0 ],
					"text" : "send title"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-94",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 5,
					"outlettype" : [ "", "", "", "", "" ],
					"patching_rect" : [ 348.0, 626.0, 79.0, 22.0 ],
					"text" : "regexp (\\\\w+)"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-105",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 315.0, 977.0, 63.0, 22.0 ],
					"text" : "/title LMF"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-100",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 327.5, 759.0, 31.0, 22.0 ],
					"text" : "/title"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-96",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 327.5, 898.0, 41.0, 22.0 ],
					"text" : "set $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-53",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 315.0, 938.0, 53.0, 22.0 ],
					"text" : "prepend"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-59",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ -17.0, 273.888716757297516, 150.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 184.934070459433997, 78.5, 110.576925098896027, 20.0 ],
					"text" : "Send offset"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-55",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ -10.0, 251.888716757297516, 150.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 70.934070459433997, 78.5, 110.576925098896027, 20.0 ],
					"text" : "pushed data"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-47",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ -10.0, 231.0, 150.0, 20.0 ],
					"presentation" : 1,
					"presentation_rect" : [ -0.065929540566003, 78.5, 59.0, 20.0 ],
					"text" : "Pot input"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-106",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 472.434070459433997, 664.0, 29.5, 22.0 ],
					"text" : "\" \""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-102",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 5,
					"outlettype" : [ "", "", "", "", "" ],
					"patching_rect" : [ 444.934070459433997, 626.0, 74.0, 22.0 ],
					"text" : "regexp Type"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-101",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 545.0, 664.0, 29.5, 22.0 ],
					"text" : "Hz"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-95",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 5,
					"outlettype" : [ "", "", "", "", "" ],
					"patching_rect" : [ 523.0, 626.0, 63.0, 22.0 ],
					"text" : "regexp LF"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-93",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 5,
					"outlettype" : [ "", "", "", "", "" ],
					"patching_rect" : [ 710.0, 626.0, 75.0, 22.0 ],
					"text" : "regexp Filter"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-88",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 5,
					"outlettype" : [ "", "", "", "", "" ],
					"patching_rect" : [ 592.22253300888201, 626.0, 74.0, 22.0 ],
					"text" : "regexp Gain"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-83",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 619.72253300888201, 664.0, 29.5, 22.0 ],
					"text" : "dB"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-23",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 5,
					"outlettype" : [ "", "", "", "", "" ],
					"patching_rect" : [ 618.049453726836646, 577.198332786560059, 149.0, 22.0 ],
					"text" : "regexp LMF|HMF|HF Freq"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-27",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 816.0, 664.0, 59.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 4.934070459433997, 7.292045831680298, 59.0, 22.0 ],
					"text" : "/p1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-70",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 782.0, 977.0, 41.0, 22.0 ],
					"text" : "set $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-57",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1353.677978515625, 1085.129168808460236, 119.0, 22.0 ],
					"text" : "/p1/offset 3252"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-5",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1353.677978515625, 843.92537201881396, 53.0, 22.0 ],
					"text" : "/p1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-91",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 457.337916276284659, 777.0, 53.0, 22.0 ],
					"text" : "/p1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-89",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 782.0, 831.050860285758972, 53.0, 22.0 ],
					"text" : "/p1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-86",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 836.0, 877.0, 41.0, 22.0 ],
					"text" : "/value"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-82",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 782.0, 938.0, 73.0, 22.0 ],
					"text" : "combine s s"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-76",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 1353.677978515625, 934.0, 73.0, 22.0 ],
					"text" : "combine s s"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-68",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1407.677978515625, 890.050860285758972, 41.0, 22.0 ],
					"text" : "/offset"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-63",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1453.677978515625, 1035.629168808460236, 53.0, 22.0 ],
					"text" : "prepend"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-64",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1353.677978515625, 972.0, 41.0, 22.0 ],
					"text" : "set $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-60",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1022.677978515625, 1040.629168808460236, 53.0, 22.0 ],
					"text" : "prepend"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-18",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 922.677978515625, 1081.629168808460236, 119.0, 22.0 ],
					"text" : "/p1/value \"1.32\""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-81",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 481.934070459433997, 898.0, 41.0, 22.0 ],
					"text" : "set $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-78",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 511.337916276284659, 759.0, 42.0, 22.0 ],
					"text" : "/name"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-72",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 457.337916276284659, 827.937823891639709, 73.0, 22.0 ],
					"text" : "combine s s"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-71",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 400.35714536053797, 938.0, 53.0, 22.0 ],
					"text" : "prepend"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-69",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 602.97253300888201, 977.0, 132.02746699111799, 22.0 ],
					"text" : "/p1/type kHz"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-67",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 602.97253300888201, 938.0, 53.0, 22.0 ],
					"text" : "prepend"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-58",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 631.0, 898.0, 41.0, 22.0 ],
					"text" : "set $1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-54",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 577.0, 711.59799587726593, 22.0, 22.0 ],
					"text" : "t b"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-87",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 631.0, 759.0, 35.0, 22.0 ],
					"text" : "/type"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-85",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 631.0, 820.937823891639709, 73.0, 22.0 ],
					"text" : "combine s s"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-84",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 400.35714536053797, 977.0, 197.0, 22.0 ],
					"text" : "/p1/name FREQ"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-56",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 683.049453726836646, 664.0, 29.5, 22.0 ],
					"text" : "kHz"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 1.0, 0.0, 0.0, 1.0 ],
					"fontsize" : 20.0,
					"id" : "obj-49",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 2050.0, 162.0, 233.0, 29.0 ],
					"text" : "Parameter OSC address",
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"comment" : "Parameter OSC ID ",
					"id" : "obj-6",
					"index" : 5,
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 2065.241762093135549, 287.356277167797089, 30.0, 30.0 ],
					"varname" : "Parameter_OSC_id"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-44",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 156.5, 1040.629168808460236, 123.0, 33.0 ],
					"text" : "request list of param names"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 1.0, 0.0, 0.0, 1.0 ],
					"fontsize" : 20.0,
					"id" : "obj-36",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 148.453303716012442, 1081.629168808460236, 535.0, 29.0 ],
					"text" : "Main Outputs",
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 1.0, 0.0, 0.0, 1.0 ],
					"fontsize" : 20.0,
					"id" : "obj-32",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1471.999999999999773, 162.0, 535.0, 29.0 ],
					"text" : "Parameter Values Updates and Sync Mouse-Potmeter",
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 1.0, 0.0, 0.0, 1.0 ],
					"fontsize" : 20.0,
					"id" : "obj-28",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 795.434070459433997, 162.0, 535.0, 29.0 ],
					"text" : "Parameter Display Values",
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 1.0, 0.0, 0.0, 1.0 ],
					"fontsize" : 20.0,
					"id" : "obj-25",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 178.434070459433997, 162.0, 535.0, 29.0 ],
					"text" : "Parameter Selector & Display Name.Type",
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"comment" : "Potentiometer input",
					"id" : "obj-20",
					"index" : 4,
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1920.0, 299.356277167797089, 30.0, 30.0 ],
					"varname" : "Potentiometer_input"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-17",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 303.5, 1118.0, 73.0, 22.0 ],
					"text" : "r ---to_serial"
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"id" : "obj-15",
					"index" : 2,
					"maxclass" : "outlet",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 303.5, 1165.0, 30.0, 30.0 ],
					"varname" : "VST_Control_Input[1]"
				}

			}
, 			{
				"box" : 				{
					"comment" : "",
					"id" : "obj-4",
					"index" : 1,
					"maxclass" : "outlet",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 156.5, 1165.0, 30.0, 30.0 ],
					"varname" : "VST_Control_Input"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-13",
					"maxclass" : "newobj",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 158.0, 1118.0, 126.0, 22.0 ],
					"text" : "r ---vst_control_output"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-12",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 158.0, 1006.759606242179871, 121.0, 22.0 ],
					"text" : "s ---vst_control_input"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-8",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 400.35714536053797, 1012.759606242179871, 75.0, 22.0 ],
					"text" : "s ---to_serial"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Verdana",
					"fontsize" : 12.0,
					"id" : "obj-221",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1622.0, 354.496247999999923, 186.0, 50.0 ],
					"text" : "use difference to know when mouse or when potentiometer is being used"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-218",
					"maxclass" : "newobj",
					"numinlets" : 6,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1520.0, 332.856277167797089, 100.0, 22.0 ],
					"text" : "scale 0 1. 0 4096"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-208",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1882.25, 699.83112370967865, 131.923078656196594, 20.0 ],
					"text" : "scale 12 bit to 0-1 float"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-204",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1816.326921343803633, 874.050860285758972, 163.0, 20.0 ],
					"text" : "only send if value is changed"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-198",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1716.722403883934021, 726.050860285758972, 99.0, 33.0 ],
					"text" : "receive selected parameter index"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-197",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1920.0, 260.888716757297516, 135.038466513156891, 33.0 ],
					"text" : "receive 12 bit value from magnetic encoder"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-196",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1510.0, 287.356277167797089, 125.0, 33.0 ],
					"text" : "receive float value from VST"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-193",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1754.865399330854416, 990.629168808460236, 174.0, 20.0 ],
					"text" : "send new index + value to VST"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-192",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1353.677978515625, 1171.759606242179871, 134.0, 20.0 ],
					"text" : "send last value to offset"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-165",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1688.865399330854416, 1013.759606242179871, 121.0, 22.0 ],
					"text" : "s ---vst_control_input"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-158",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1807.0, 662.331124246120453, 32.0, 22.0 ],
					"text" : "gate"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-150",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1889.0, 386.323837578296661, 50.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ -0.065929540566003, 51.292045831680298, 69.0, 22.0 ],
					"text" : "3042"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-148",
					"maxclass" : "toggle",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1611.0, 494.467560410499573, 24.0, 24.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-139",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "bang" ],
					"patching_rect" : [ 1655.0, 417.467560410499573, 29.5, 22.0 ],
					"text" : "b"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-126",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1898.25, 793.920422852039337, 59.0, 22.0 ],
					"text" : "0.742676"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-113",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1365.177978515625, 696.59799587726593, 50.0, 22.0 ],
					"text" : "3252"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-104",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1598.0, 621.331124246120453, 50.0, 22.0 ],
					"text" : "0"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-50",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1754.760870397090912, 831.050860285758972, 84.239129602909088, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 70.934070459433997, 51.292045831680298, 110.576925098896027, 22.0 ],
					"text" : "12 0.742676"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Verdana",
					"fontsize" : 12.0,
					"id" : "obj-42",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1320.5, 662.331124246120453, 169.0, 21.0 ],
					"text" : "if trigger = 0, send values"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Verdana",
					"fontsize" : 12.0,
					"id" : "obj-41",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1598.0, 648.331124246120453, 169.0, 21.0 ],
					"text" : "if trigger = 1, send values"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Verdana",
					"fontsize" : 12.0,
					"id" : "obj-40",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1589.5, 875.050860285758972, 146.0, 21.0 ],
					"text" : "last value after 150ms"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Verdana",
					"fontsize" : 12.0,
					"id" : "obj-31",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1578.0, 576.337098717689514, 101.0, 21.0 ],
					"text" : "inverse trigger"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Verdana",
					"fontsize" : 12.0,
					"id" : "obj-29",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1641.0, 498.467560410499573, 137.0, 50.0 ],
					"text" : "Only send offset if pot value outside +-5 of VST value"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-75",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1820.0, 793.920422852039337, 45.0, 22.0 ],
					"text" : "pak 0 f"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-74",
					"maxclass" : "newobj",
					"numinlets" : 6,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1882.25, 737.050860285758972, 100.0, 22.0 ],
					"text" : "scale 0 4096. 0 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-46",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1492.0, 875.050860285758972, 50.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 184.934070459433997, 51.292045831680298, 110.538462549448013, 22.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Verdana",
					"fontsize" : 12.0,
					"id" : "obj-30",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1315.5, 737.050860285758972, 174.0, 21.0 ],
					"text" : "Only output last send value"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-33",
					"maxclass" : "button",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1470.177978515625, 934.0, 20.0, 20.0 ]
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Verdana",
					"fontsize" : 12.0,
					"id" : "obj-35",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "bang", "int" ],
					"patching_rect" : [ 1489.5, 737.050860285758972, 32.0, 23.0 ],
					"text" : "t b i"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Verdana",
					"fontsize" : 12.0,
					"id" : "obj-37",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 1448.5, 784.050860285758972, 54.0, 23.0 ],
					"text" : "del 150"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Verdana",
					"fontsize" : 12.0,
					"id" : "obj-38",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"patching_rect" : [ 1492.0, 831.050860285758972, 29.5, 23.0 ],
					"text" : "int"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-19",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1565.0, 534.467560410499573, 50.0, 22.0 ],
					"text" : "1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-16",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "int" ],
					"patching_rect" : [ 1548.0, 576.337098717689514, 29.5, 22.0 ],
					"text" : "!- 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-11",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1489.5, 662.331124246120453, 32.0, 22.0 ],
					"text" : "gate"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-9",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1548.0, 461.198332786560059, 251.0, 22.0 ],
					"text" : "if ($i1 < ($i2-3)) || ($i1 > ($i2+3)) then 0 else 1"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-62",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 1820.0, 737.050860285758972, 50.0, 22.0 ],
					"text" : "12"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-14",
					"maxclass" : "newobj",
					"numinlets" : 2,
					"numoutlets" : 2,
					"outlettype" : [ "", "" ],
					"patching_rect" : [ 1754.760870397090912, 874.050860285758972, 60.0, 22.0 ],
					"text" : "zl.change"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-152",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1841.0, 832.050860285758972, 146.0, 20.0 ],
					"text" : " new param index + value"
				}

			}
, 			{
				"box" : 				{
					"comment" : "All Parameter Index + Values Input",
					"id" : "obj-7",
					"index" : 3,
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 953.5, 288.123149335384369, 30.0, 30.0 ],
					"varname" : "Parameter_Values_Input"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Verdana",
					"fontsize" : 12.0,
					"id" : "obj-77",
					"linecount" : 5,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 817.112048975058997, 741.92537201881396, 135.0, 79.0 ],
					"text" : "Reduce number of messages per 8ms to avoid laggy display when using mouse"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-202",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 734.434070459433997, 479.356277167797089, 127.038466513156891, 20.0 ],
					"text" : "receive selected index"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-195",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 950.0, 261.356277167797089, 204.0, 20.0 ],
					"text" : "receive all parameter index + values "
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-190",
					"linecount" : 3,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1078.391282796859741, 731.629168808460236, 114.0, 47.0 ],
					"text" : "send raw value to update offset magnetic encoder"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-182",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1139.391282796859741, 697.59799587726593, 91.0, 20.0 ],
					"text" : "selected values"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-181",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 1021.307691633701324, 349.0, 107.384616732597351, 33.0 ],
					"text" : "all values from parameter index"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-176",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 922.677978515625, 1171.759606242179871, 97.421066790819168, 33.0 ],
					"text" : "send selected value to display"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-138",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 997.289999999999964, 684.59799587726593, 59.0, 22.0 ],
					"text" : "0.742676"
				}

			}
, 			{
				"box" : 				{
					"fontname" : "Verdana",
					"fontsize" : 12.0,
					"id" : "obj-34",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 749.226892709732056, 697.59799587726593, 173.0, 36.0 ],
					"text" : " display value of selected parameter index"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-52",
					"linecount" : 5,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 809.0, 525.198332786560059, 121.0, 74.0 ],
					"text" : "Only update the selected parameter, ignore other parameters (edits by mouse for example)"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-185",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 925.5, 684.59799587726593, 57.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 292.5, 7.292045831680298, 57.0, 22.0 ],
					"text" : "\"1.32\""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-183",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "float", "" ],
					"patching_rect" : [ 940.5, 438.96153849363327, 63.0, 22.0 ],
					"text" : "unpack f s"
				}

			}
, 			{
				"box" : 				{
					"comment" : "Bang to initatialize",
					"id" : "obj-1",
					"index" : 1,
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 388.934070459433997, 236.0, 30.0, 30.0 ],
					"varname" : "Bang"
				}

			}
, 			{
				"box" : 				{
					"comment" : "Parameter Names List",
					"id" : "obj-2",
					"index" : 2,
					"maxclass" : "inlet",
					"numinlets" : 0,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 569.241762093135321, 241.888716757297516, 30.0, 30.0 ],
					"varname" : "Parameter_Names"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-207",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 393.934070459433997, 280.856277167797089, 194.0, 33.0 ],
					"text" : "Add dummy \"Selected Parameter\" to fix counting from 1 instead of 0."
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-205",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 166.5, 626.0, 76.0, 60.0 ],
					"text" : "Get current value of parameter index"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-201",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 481.934070459433997, 447.230772376060486, 123.0, 33.0 ],
					"text" : "send selected param index to filter values"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-194",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 569.241762093135321, 217.888716757297516, 138.0, 20.0 ],
					"text" : "get all parameter names"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-180",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 433.35714536053797, 1040.629168808460236, 221.61538764834404, 20.0 ],
					"text" : "send selected name and type to display"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-177",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 344.934070459433997, 209.0, 178.038466513156891, 20.0 ],
					"text" : "populate menu list on start"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-170",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 236.892857432365417, 333.856277167797089, 110.788466513156891, 60.0 ],
					"text" : "Get list of all parameter names to be pushed to \"r parameter_names\""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-117",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "bang" ],
					"patching_rect" : [ 365.934070459433997, 501.0, 22.0, 22.0 ],
					"text" : "t b"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-79",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "bang", "bang", "bang" ],
					"patching_rect" : [ 344.934070459433997, 280.856277167797089, 40.0, 22.0 ],
					"text" : "b 3"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-162",
					"linecount" : 4,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 233.767857432365417, 400.96153849363327, 117.038466513156891, 60.0 ],
					"text" : "Select Parameter and push index and value to Parameter index as pak list"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-156",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ 530.549453726836646, 401.96153849363327, 182.0, 20.0 ],
					"text" : "all parameters indexes + names "
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-144",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 271.934070459433997, 542.730772376060486, 29.5, 22.0 ],
					"text" : "12"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-132",
					"maxclass" : "newobj",
					"numinlets" : 1,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 569.241762093135321, 332.856277167797089, 96.0, 22.0 ],
					"text" : "prepend append"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-131",
					"items" : [ "Select Parameter", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset", ",", "Bypass", ",", "External S/C", ",", "Input Trim", ",", "Polarity", ",", "Low Pass Filter", ",", "High Pass Filter", ",", "EQ In", ",", "EQ Type", ",", "LF Type", ",", "LF Frequency", ",", "LF Gain", ",", "LMF Frequency", ",", "LMF Gain", ",", "LMF Q", ",", "HMF Freq", ",", "HMF Gain", ",", "HMF Q", ",", "HF Type", ",", "HF Freq", ",", "HF Gain", ",", "Dynamics In", ",", "Compressor Peak", ",", "Compressor Fast Attack", ",", "Compressor Ratio", ",", "Compressor Threshold", ",", "Compressor Release", ",", "Compressor Mix", ",", "Gate Expander", ",", "Gate Attack", ",", "Gate Hold", ",", "Gate Threshold", ",", "Gate Range", ",", "Gate Release", ",", "Filters to Input", ",", "Dynamics Pre-EQ", ",", "Filters to S/C", ",", "EQ to S/C", ",", "S/C Listen", ",", "Fader Level", ",", "Output Trim", ",", "Width", ",", "Pan", ",", "Legacy Cut", ",", "Legacy Solo", ",", "Legacy Solo Safe", ",", "GroupSense", ",", "Filters In", ",", "Width Mode", ",", "Width Frequency", ",", "Compressor Auto Make-up", ",", "Compressor Auto Make-up Offset" ],
					"maxclass" : "umenu",
					"numinlets" : 1,
					"numoutlets" : 3,
					"outlettype" : [ "int", "", "" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 365.934070459433997, 400.96153849363327, 160.0, 22.0 ],
					"presentation" : 1,
					"presentation_rect" : [ 76.934070459433997, 7.292045831680298, 208.538462549448013, 22.0 ],
					"varname" : "Select_Parameter"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-111",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 158.0, 333.856277167797089, 49.0, 22.0 ],
					"text" : "params"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-135",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 525.934070459433997, 332.856277167797089, 35.0, 22.0 ],
					"text" : "clear"
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-157",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 365.934070459433997, 332.856277167797089, 153.0, 22.0 ],
					"text" : "append \"Select Parameter\""
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-26",
					"maxclass" : "message",
					"numinlets" : 2,
					"numoutlets" : 1,
					"outlettype" : [ "" ],
					"patching_rect" : [ 267.287090688943863, 603.0, 50.0, 22.0 ],
					"text" : "get $1"
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.0, 0.0, 0.0, 1.0 ],
					"id" : "obj-21",
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ -25.0, 167.0, 150.0, 34.0 ],
					"presentation" : 1,
					"presentation_rect" : [ -4.065929540566003, 1.292045831680298, 294.576925098896027, 34.0 ],
					"text" : "\n",
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"bgcolor" : [ 0.666666666666667, 0.666666666666667, 0.666666666666667, 1.0 ],
					"id" : "obj-22",
					"linecount" : 2,
					"maxclass" : "comment",
					"numinlets" : 1,
					"numoutlets" : 0,
					"patching_rect" : [ -10.0, 182.0, 150.0, 47.0 ],
					"presentation" : 1,
					"presentation_linecount" : 2,
					"presentation_rect" : [ -9.065929540566003, -5.207954168319702, 408.576925098896027, 47.0 ],
					"text" : "\n\n",
					"textcolor" : [ 1.0, 1.0, 1.0, 1.0 ]
				}

			}
, 			{
				"box" : 				{
					"id" : "obj-163",
					"maxclass" : "number",
					"numinlets" : 1,
					"numoutlets" : 2,
					"outlettype" : [ "", "bang" ],
					"parameter_enable" : 0,
					"patching_rect" : [ 1520.0, 368.49624799999998, 50.0, 22.0 ]
				}

			}
 ],
		"lines" : [ 			{
				"patchline" : 				{
					"destination" : [ "obj-125", 0 ],
					"source" : [ "obj-1", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-96", 0 ],
					"source" : [ "obj-100", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-128", 1 ],
					"source" : [ "obj-101", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-106", 0 ],
					"source" : [ "obj-102", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-108", 1 ],
					"source" : [ "obj-103", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"source" : [ "obj-105", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-128", 1 ],
					"source" : [ "obj-106", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-131", 0 ],
					"source" : [ "obj-107", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-98", 0 ],
					"source" : [ "obj-108", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"source" : [ "obj-109", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-113", 1 ],
					"order" : 1,
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-35", 0 ],
					"order" : 0,
					"source" : [ "obj-11", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-79", 0 ],
					"source" : [ "obj-110", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"source" : [ "obj-111", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-116", 0 ],
					"source" : [ "obj-115", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-130", 0 ],
					"source" : [ "obj-116", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-128", 0 ],
					"order" : 1,
					"source" : [ "obj-117", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"order" : 0,
					"source" : [ "obj-117", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-121", 1 ],
					"source" : [ "obj-119", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-79", 0 ],
					"source" : [ "obj-120", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-122", 0 ],
					"source" : [ "obj-121", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-105", 0 ],
					"order" : 3,
					"source" : [ "obj-125", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-144", 0 ],
					"order" : 4,
					"source" : [ "obj-125", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-185", 0 ],
					"order" : 0,
					"source" : [ "obj-125", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-69", 0 ],
					"order" : 1,
					"source" : [ "obj-125", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 0 ],
					"order" : 2,
					"source" : [ "obj-125", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-158", 1 ],
					"source" : [ "obj-127", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-67", 0 ],
					"source" : [ "obj-128", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-4", 0 ],
					"source" : [ "obj-13", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-154", 0 ],
					"source" : [ "obj-130", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-102", 0 ],
					"order" : 5,
					"source" : [ "obj-131", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-117", 0 ],
					"order" : 0,
					"source" : [ "obj-131", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-144", 1 ],
					"order" : 1,
					"source" : [ "obj-131", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-144", 0 ],
					"order" : 2,
					"source" : [ "obj-131", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"midpoints" : [ 445.934070459433997, 537.0, 627.549453726836646, 537.0 ],
					"order" : 1,
					"source" : [ "obj-131", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-3", 0 ],
					"order" : 6,
					"source" : [ "obj-131", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-54", 0 ],
					"order" : 3,
					"source" : [ "obj-131", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-88", 0 ],
					"order" : 2,
					"source" : [ "obj-131", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-93", 0 ],
					"midpoints" : [ 445.934070459433997, 537.0, 603.0, 537.0, 603.0, 612.0, 719.5, 612.0 ],
					"order" : 0,
					"source" : [ "obj-131", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-94", 0 ],
					"order" : 7,
					"source" : [ "obj-131", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-95", 0 ],
					"order" : 4,
					"source" : [ "obj-131", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-131", 0 ],
					"source" : [ "obj-132", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-71", 0 ],
					"source" : [ "obj-134", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-131", 0 ],
					"source" : [ "obj-135", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-119", 0 ],
					"order" : 1,
					"source" : [ "obj-138", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-121", 0 ],
					"order" : 2,
					"source" : [ "obj-138", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-218", 0 ],
					"order" : 0,
					"source" : [ "obj-138", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"source" : [ "obj-139", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-165", 0 ],
					"order" : 1,
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-189", 1 ],
					"order" : 0,
					"source" : [ "obj-14", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-26", 0 ],
					"order" : 2,
					"source" : [ "obj-144", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-39", 1 ],
					"order" : 1,
					"source" : [ "obj-144", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-62", 1 ],
					"order" : 0,
					"source" : [ "obj-144", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-158", 0 ],
					"source" : [ "obj-148", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-127", 1 ],
					"order" : 0,
					"source" : [ "obj-150", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-139", 0 ],
					"order" : 4,
					"source" : [ "obj-150", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-158", 1 ],
					"order" : 1,
					"source" : [ "obj-150", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-45", 0 ],
					"order" : 3,
					"source" : [ "obj-150", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 1 ],
					"order" : 2,
					"source" : [ "obj-150", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-134", 1 ],
					"order" : 0,
					"source" : [ "obj-154", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-134", 0 ],
					"order" : 1,
					"source" : [ "obj-154", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-115", 0 ],
					"source" : [ "obj-155", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"source" : [ "obj-155", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-131", 0 ],
					"source" : [ "obj-157", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-62", 0 ],
					"order" : 1,
					"source" : [ "obj-158", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-74", 0 ],
					"order" : 0,
					"source" : [ "obj-158", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 1 ],
					"order" : 1,
					"source" : [ "obj-159", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-166", 0 ],
					"order" : 2,
					"source" : [ "obj-159", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-9", 0 ],
					"order" : 0,
					"source" : [ "obj-159", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-104", 1 ],
					"order" : 0,
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-11", 0 ],
					"order" : 1,
					"source" : [ "obj-16", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-159", 1 ],
					"order" : 0,
					"source" : [ "obj-163", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-159", 0 ],
					"order" : 1,
					"source" : [ "obj-163", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-15", 0 ],
					"source" : [ "obj-17", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-144", 0 ],
					"source" : [ "obj-173", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-122", 0 ],
					"source" : [ "obj-18", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-138", 1 ],
					"order" : 0,
					"source" : [ "obj-183", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-138", 0 ],
					"order" : 1,
					"source" : [ "obj-183", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-48", 0 ],
					"source" : [ "obj-183", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 0 ],
					"order" : 1,
					"source" : [ "obj-185", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-60", 0 ],
					"order" : 0,
					"source" : [ "obj-185", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-132", 0 ],
					"source" : [ "obj-2", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-150", 1 ],
					"order" : 0,
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-150", 0 ],
					"order" : 1,
					"source" : [ "obj-20", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-163", 0 ],
					"source" : [ "obj-218", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-56", 0 ],
					"source" : [ "obj-23", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-173", 0 ],
					"source" : [ "obj-24", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-12", 0 ],
					"source" : [ "obj-26", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 1 ],
					"order" : 0,
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-5", 0 ],
					"order" : 1,
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-89", 1 ],
					"order" : 4,
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-89", 0 ],
					"order" : 5,
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-91", 1 ],
					"order" : 6,
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-99", 1 ],
					"order" : 2,
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-99", 0 ],
					"order" : 3,
					"source" : [ "obj-27", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-102", 0 ],
					"source" : [ "obj-3", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-23", 0 ],
					"source" : [ "obj-3", 5 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-88", 0 ],
					"source" : [ "obj-3", 3 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-93", 0 ],
					"midpoints" : [ 464.934070459433997, 612.0, 719.5, 612.0 ],
					"source" : [ "obj-3", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-95", 0 ],
					"source" : [ "obj-3", 4 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-43", 0 ],
					"source" : [ "obj-33", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-37", 0 ],
					"source" : [ "obj-35", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-38", 1 ],
					"source" : [ "obj-35", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-38", 0 ],
					"source" : [ "obj-37", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-46", 0 ],
					"source" : [ "obj-38", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-183", 0 ],
					"source" : [ "obj-39", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"source" : [ "obj-43", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-50", 0 ],
					"source" : [ "obj-45", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-33", 0 ],
					"order" : 1,
					"source" : [ "obj-46", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-43", 1 ],
					"order" : 0,
					"source" : [ "obj-46", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-185", 1 ],
					"source" : [ "obj-48", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-185", 0 ],
					"source" : [ "obj-48", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-68", 0 ],
					"order" : 0,
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-76", 0 ],
					"order" : 1,
					"source" : [ "obj-5", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-14", 0 ],
					"source" : [ "obj-50", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-24", 0 ],
					"source" : [ "obj-51", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-105", 1 ],
					"order" : 0,
					"source" : [ "obj-53", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-105", 0 ],
					"order" : 1,
					"source" : [ "obj-53", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-100", 0 ],
					"order" : 3,
					"source" : [ "obj-54", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-78", 0 ],
					"order" : 1,
					"source" : [ "obj-54", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-87", 0 ],
					"order" : 0,
					"source" : [ "obj-54", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-91", 0 ],
					"order" : 2,
					"source" : [ "obj-54", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-128", 1 ],
					"source" : [ "obj-56", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-122", 0 ],
					"order" : 1,
					"source" : [ "obj-57", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-141", 0 ],
					"order" : 0,
					"source" : [ "obj-57", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-67", 0 ],
					"source" : [ "obj-58", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 1 ],
					"order" : 0,
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-27", 0 ],
					"order" : 1,
					"source" : [ "obj-6", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-18", 1 ],
					"source" : [ "obj-60", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-75", 0 ],
					"source" : [ "obj-62", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-57", 1 ],
					"order" : 0,
					"source" : [ "obj-63", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-57", 0 ],
					"order" : 1,
					"source" : [ "obj-63", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-63", 0 ],
					"source" : [ "obj-64", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-127", 0 ],
					"source" : [ "obj-65", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-69", 1 ],
					"order" : 0,
					"source" : [ "obj-67", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-69", 0 ],
					"order" : 1,
					"source" : [ "obj-67", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-76", 1 ],
					"source" : [ "obj-68", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-10", 0 ],
					"source" : [ "obj-69", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-39", 0 ],
					"source" : [ "obj-7", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-60", 0 ],
					"source" : [ "obj-70", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 1 ],
					"order" : 0,
					"source" : [ "obj-71", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-84", 0 ],
					"order" : 1,
					"source" : [ "obj-71", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-81", 0 ],
					"source" : [ "obj-72", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-126", 1 ],
					"order" : 0,
					"source" : [ "obj-74", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-75", 1 ],
					"order" : 1,
					"source" : [ "obj-74", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-50", 1 ],
					"source" : [ "obj-75", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-64", 0 ],
					"source" : [ "obj-76", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-72", 1 ],
					"source" : [ "obj-78", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-111", 0 ],
					"source" : [ "obj-79", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-135", 0 ],
					"source" : [ "obj-79", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-157", 0 ],
					"source" : [ "obj-79", 1 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-71", 0 ],
					"source" : [ "obj-81", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-70", 0 ],
					"source" : [ "obj-82", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-128", 1 ],
					"source" : [ "obj-83", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-8", 0 ],
					"source" : [ "obj-84", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-58", 0 ],
					"source" : [ "obj-85", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-82", 1 ],
					"source" : [ "obj-86", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-85", 1 ],
					"source" : [ "obj-87", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-83", 0 ],
					"source" : [ "obj-88", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-82", 0 ],
					"order" : 1,
					"source" : [ "obj-89", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-86", 0 ],
					"order" : 0,
					"source" : [ "obj-89", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-148", 0 ],
					"order" : 0,
					"source" : [ "obj-9", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-16", 0 ],
					"order" : 2,
					"source" : [ "obj-9", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-19", 1 ],
					"order" : 1,
					"source" : [ "obj-9", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-72", 0 ],
					"order" : 1,
					"source" : [ "obj-91", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-85", 0 ],
					"order" : 0,
					"source" : [ "obj-91", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-56", 0 ],
					"source" : [ "obj-93", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-155", 0 ],
					"source" : [ "obj-94", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-101", 0 ],
					"source" : [ "obj-95", 2 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-53", 0 ],
					"source" : [ "obj-96", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-119", 0 ],
					"source" : [ "obj-98", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-103", 0 ],
					"order" : 0,
					"source" : [ "obj-99", 0 ]
				}

			}
, 			{
				"patchline" : 				{
					"destination" : [ "obj-108", 0 ],
					"order" : 1,
					"source" : [ "obj-99", 0 ]
				}

			}
 ],
		"styles" : [ 			{
				"name" : "Audiomix",
				"default" : 				{
					"bgfillcolor" : 					{
						"angle" : 270.0,
						"color" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
						"color1" : [ 0.376471, 0.384314, 0.4, 1.0 ],
						"color2" : [ 0.290196, 0.309804, 0.301961, 1.0 ],
						"proportion" : 0.39,
						"type" : "gradient"
					}

				}
,
				"parentstyle" : "",
				"multi" : 0
			}
, 			{
				"name" : "newobjBlue-1",
				"default" : 				{
					"accentcolor" : [ 0.317647, 0.654902, 0.976471, 1.0 ]
				}
,
				"parentstyle" : "",
				"multi" : 0
			}
, 			{
				"name" : "newobjGreen-1",
				"default" : 				{
					"accentcolor" : [ 0.0, 0.533333, 0.168627, 1.0 ]
				}
,
				"parentstyle" : "",
				"multi" : 0
			}
, 			{
				"name" : "newobjRed-1",
				"default" : 				{
					"accentcolor" : [ 0.784314, 0.145098, 0.023529, 1.0 ]
				}
,
				"parentstyle" : "",
				"multi" : 0
			}
, 			{
				"name" : "newobjYellow-1",
				"default" : 				{
					"accentcolor" : [ 0.82517, 0.78181, 0.059545, 1.0 ],
					"fontsize" : [ 12.059008 ]
				}
,
				"parentstyle" : "",
				"multi" : 0
			}
 ],
		"saved_attribute_attributes" : 		{
			"default_plcolor" : 			{
				"expression" : ""
			}

		}

	}

}
