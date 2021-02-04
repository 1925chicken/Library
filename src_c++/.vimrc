call plug#begin('~/.vim/plugged')
Plug 'thinca/vim-quickrun', {'on': 'QuickRun'}
Plug 'Shougo/vimproc.vim', {'do': 'make'}
" ディレクトリツリーを表示する
Plug 'scrooloose/nerdtree', { 'on':  'NERDTreeToggle' }
Plug 'sheerun/vim-polyglot'
if has('nvim')
  Plug 'Shougo/deoplete.nvim', { 'do': ':UpdateRemotePlugins' }
else
  Plug 'Shougo/deoplete.nvim'
  Plug 'roxma/nvim-yarp'
  Plug 'roxma/vim-hug-neovim-rpc'
endif
Plug 'Shougo/neco-syntax' " general
Plug 'deoplete-plugins/deoplete-jedi' " python
Plug 'Shougo/deoplete-clangx' " c, cpp
Plug 'Shougo/neoinclude.vim' " header
Plug 'wokalski/autocomplete-flow' " javascript
Plug 'Shougo/context_filetype.vim' " change filetype according context
Plug 'jacoborus/tender.vim'
Plug 'cohama/lexima.vim'
if (has("termguicolors"))
	set termguicolors
endif

let g:deoplete#enable_at_startup = 1
let g:deoplete#sources#jedi#extra_path=system('which python')[:-2] " for pyenv and virtualenv
let g:deoplete#sources#jedi#show_docstring=0
" close preview window after completion
autocmd InsertLeave,CompleteDone * if pumvisible() == 0 | pclose | endif
Plug 'Shougo/neosnippet'
Plug 'Shougo/neosnippet-snippets'

imap <C-k>     <Plug>(neosnippet_expand_or_jump)
smap <C-k>     <Plug>(neosnippet_expand_or_jump)
xmap <C-k>     <Plug>(neosnippet_expand_target)
let g:neosnippet#snippets_directory = '$HOME/.vim/snippets'
let g:neosnippet#enable_snipmate_compatibility = 1
let g:neosnippet#conceal_char = '|'
if has('conceal')
  set conceallevel=2 concealcursor=niv
endif
autocmd InsertLeave * NeoSnippetClearMarkers
snoremap <silent><ESC> <ESC>:NeoSnippetClearMarkers<CR>
call plug#end()
set number
set fenc=utf-8
set autoread
set hidden
set showcmd
set cursorline
set smartindent
set showmatch
syntax enable
colorscheme tender
set tabstop=4
set shiftwidth=4
let g:lexima_enable_basic_rules=1
set clipboard=unnamedplus
set guioptions+=a
inoremap { {}<LEFT>
inoremap ( ()<LEFT>
inoremap [ []<LEFT>
inoremap { {}<Left>
inoremap {<Enter> {}<Left><CR><ESC><S-o>
inoremap ( ()<ESC>i
inoremap (<Enter> ()<Left><CR><ESC><S-o>
inoremap [<Enter> []<Left><CR><ESC><S-o>
