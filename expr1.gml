graph
[
	node
	[
		id 140343118931936
		label "POWER"
	]

	node
	[
		id 140343118931984
		label "PLUS"
	]

	node
	[
		id 140343118932032
		label "PLUS"
	]

	node
	[
		id 140343118932112
		label "SIN"
	]

	node
	[
		id 140343118932160
		label "x"
	]

	edge
	[
		source 140343118932112
		target 140343118932160
		label "left"
	]
	edge
	[
		source 140343118932032
		target 140343118932112
		label "left"
	]
	node
	[
		id 140343118932208
		label "TAN"
	]

	node
	[
		id 140343118932256
		label "x"
	]

	edge
	[
		source 140343118932208
		target 140343118932256
		label "left"
	]
	edge
	[
		source 140343118932032
		target 140343118932208
		label "right"
	]
	edge
	[
		source 140343118931984
		target 140343118932032
		label "left"
	]
	node
	[
		id 140343118932304
		label "MULTIPLY"
	]

	node
	[
		id 140343118932352
		label "3"
	]

	edge
	[
		source 140343118932304
		target 140343118932352
		label "left"
	]
	node
	[
		id 140343118932400
		label "x"
	]

	edge
	[
		source 140343118932304
		target 140343118932400
		label "right"
	]
	edge
	[
		source 140343118931984
		target 140343118932304
		label "right"
	]
	edge
	[
		source 140343118931936
		target 140343118931984
		label "left"
	]
	node
	[
		id 140343118932448
		label "DIVIDE"
	]

	node
	[
		id 140343118932496
		label "1"
	]

	edge
	[
		source 140343118932448
		target 140343118932496
		label "left"
	]
	node
	[
		id 140343118932544
		label "x"
	]

	edge
	[
		source 140343118932448
		target 140343118932544
		label "right"
	]
	edge
	[
		source 140343118931936
		target 140343118932448
		label "right"
	]
]
