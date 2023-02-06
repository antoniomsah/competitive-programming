require('nvim-treesitter.configs').setup {
	ensure_installed = { "c", "cpp", "lua", "python" },

	highlight = {
		enable = true,
	},
}
