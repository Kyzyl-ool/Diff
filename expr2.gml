graph
[
	node
	[
		id 140314002073920
		label "DIVIDE"
	]

	node
	[
		id 140314002073968
		label "MINUS"
	]

	node
	[
		id 140314002074064
		label "MULTIPLY"
	]

	node
	[
		id 140314002074736
		label "MULTIPLY"
	]

	node
	[
		id 140314002074784
		label "2"
	]

	edge
	[
		source 140314002074736
		target 140314002074784
		label "left"
	]
	node
	[
		id 140314002074832
		label "POWER"
	]

	node
	[
		id 140314002074880
		label "x"
	]

	edge
	[
		source 140314002074832
		target 140314002074880
		label "left"
	]
	node
	[
		id 140314002074928
		label "MINUS"
	]

	node
	[
		id 140314002074976
		label "2"
	]

	edge
	[
		source 140314002074928
		target 140314002074976
		label "left"
	]
	node
	[
		id 140314002075024
		label "1"
	]

	edge
	[
		source 140314002074928
		target 140314002075024
		label "right"
	]
	edge
	[
		source 140314002074832
		target 140314002074928
		label "right"
	]
	edge
	[
		source 140314002074736
		target 140314002074832
		label "right"
	]
	edge
	[
		source 140314002074064
		target 140314002074736
		label "left"
	]
	node
	[
		id 140314003111984
		label "x"
	]

	edge
	[
		source 140314002074064
		target 140314003111984
		label "right"
	]
	edge
	[
		source 140314002073968
		target 140314002074064
		label "left"
	]
	node
	[
		id 140314004160512
		label "MINUS"
	]

	node
	[
		id 140314004160560
		label "POWER"
	]

	node
	[
		id 140314004160608
		label "x"
	]

	edge
	[
		source 140314004160560
		target 140314004160608
		label "left"
	]
	node
	[
		id 140314004160656
		label "2"
	]

	edge
	[
		source 140314004160560
		target 140314004160656
		label "right"
	]
	edge
	[
		source 140314004160512
		target 140314004160560
		label "left"
	]
	node
	[
		id 140314004160704
		label "1"
	]

	edge
	[
		source 140314004160512
		target 140314004160704
		label "right"
	]
	edge
	[
		source 140314002073968
		target 140314004160512
		label "right"
	]
	edge
	[
		source 140314002073920
		target 140314002073968
		label "left"
	]
	node
	[
		id 140314002074016
		label "POWER"
	]

	node
	[
		id 140314002074160
		label "x"
	]

	edge
	[
		source 140314002074016
		target 140314002074160
		label "left"
	]
	node
	[
		id 140314002074208
		label "2"
	]

	edge
	[
		source 140314002074016
		target 140314002074208
		label "right"
	]
	edge
	[
		source 140314002073920
		target 140314002074016
		label "right"
	]
]
