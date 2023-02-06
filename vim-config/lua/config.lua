local o = vim.o;

o.tabstop	 		= 4
o.shiftwidth 		= 4

o.number 			= true
o.relativenumber 	= true
o.ruler 			= true
o.list 				= true
o.smartindent 		= true
o.termguicolors 	= true

-- Dracula theme
local dracula = require("dracula")
vim.cmd [[colorscheme dracula]]
