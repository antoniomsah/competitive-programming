vim.api.nvim_create_autocmd('BufWritePost', {
    group = vim.api.nvim_create_augroup('PACKER', { clear = true }),
    pattern = 'plugins.lua',
    command = 'source <afile> | PackerCompile',
})

return require('packer').startup({
	function(use)
		-- Package Manager
		use 'wbthomason/packer.nvim'

		-- Dracula's theme
		use {
			'Mofiqul/dracula.nvim',
			config = function()
				require('themes.dracula')
			end,
		}

		-- Snippets
		use {
			'hrsh7th/nvim-cmp',
			config = function()
				require('plugins.cmp')
			end,
		}

		use { 'saadparwaiz1/cmp_luasnip' }

		use {
			'L3MON4D3/LuaSnip',
			after = 'nvim-cmp',
			config = function()
				require('plugins.snippets')
			end,
		}

		-- LSP
		use {
		  'VonHeikemen/lsp-zero.nvim',
		  branch = 'v2.x',
		  requires = {
			-- LSP Support
			{'neovim/nvim-lspconfig'},             -- Required
			{                                      -- Optional
			  'williamboman/mason.nvim',
			  run = function()
				pcall(vim.cmd, 'MasonUpdate')
			  end,
			},
			{'williamboman/mason-lspconfig.nvim'}, -- Optional
			{'hrsh7th/nvim-cmp'},
			{'hrsh7th/cmp-nvim-lsp'},
			{'L3MON4D3/LuaSnip'},
		  }
		}

		-- Colorizer
		use {
			'norcalli/nvim-colorizer.lua',
			config = function()
				require('colorizer').setup()
			end,
		}

		-- Better status line
		use {
			'nvim-lualine/lualine.nvim',
			requires = { 'kyazdani42/nvim-web-devicons', opt = true },
			config = function()
				require('plugins.lualine')
			end,
		}

		-- Treesitter
		use {
			'nvim-treesitter/nvim-treesitter',
			run = function()
				local ts_update = require('nvim-treesitter.install').update({ with_sync = true })
				ts_update()
			end,

			config = function()
				require('plugins.treesitter')
			end,
    	}
	end,

	config = {
		display = {
			open_fn = function()
				return require('packer.util').float({ border = 'single' })
			end,
		},
	},
})
