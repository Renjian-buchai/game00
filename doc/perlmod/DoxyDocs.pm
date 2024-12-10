$doxydocs=
{
  classes => [
    {
      name => 'explorer_t',
      kind => 'class',
      base => [
        {
          name => 'scene',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'explorer.hh'
      },
      all_members => [
        {
          name => 'background',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'explorer_t'
        },
        {
          name => 'context',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'createFilesystemEntry',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'explorer_t'
        },
        {
          name => 'downloadBounds',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'explorer_t'
        },
        {
          name => 'explorer_t',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'explorer_t'
        },
        {
          name => 'handle',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'explorer_t'
        },
        {
          name => 'items',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'explorer_t'
        },
        {
          name => 'loadTexture',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'nameWrapLength',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'explorer_t'
        },
        {
          name => 'render',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'explorer_t'
        },
        {
          name => 'saveData',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'explorer_t'
        },
        {
          name => 'scene',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'update',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'explorer_t'
        },
        {
          name => '~explorer_t',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'explorer_t'
        },
        {
          name => '~scene',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'scene'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'explorer_t',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a new explorer t object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Called only once when WM is initialised'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'context'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'game context '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'context',
                type => 'game *'
              }
            ]
          },
          {
            kind => 'function',
            name => '~explorer_t',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Destroy the explorer t object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Called only when the wm is destroyed '
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'update',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Update logic for the explorer t object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Realistically, does absolutely nothing.'
                },
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'std::pair<scenes, sceneData> Returns the scene to be changed to, and the data that scene should contain '
                    }
                  ]
                }
              ]
            },
            type => 'std::pair< scenes, sceneData >',
            const => 'no',
            volatile => 'no',
            parameters => [
            ],
            reimplements => {
              name => 'update'
            }
          },
          {
            kind => 'function',
            name => 'render',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Renders explorer, and files. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ],
            reimplements => {
              name => 'render'
            }
          },
          {
            kind => 'function',
            name => 'handle',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Handles mouse movement and file selection. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'event'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Event to be handled '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'std::pair<scenes, sceneData> Returns the scene to be changed to, and the data that scene should contain '
                    }
                  ]
                }
              ]
            },
            type => 'std::pair< scenes, sceneData >',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'event',
                type => 'const SDL_Event &'
              }
            ],
            reimplements => {
              name => 'handle'
            }
          },
          {
            kind => 'function',
            name => 'createFilesystemEntry',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Creates texture to display in filesystem. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'text'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Text to be inserted as name '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'size'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Text to be inserted in size '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL_Texture* Texture at size width x 40 to make the text itself more readable '
                    }
                  ]
                }
              ]
            },
            type => 'SDL_Texture *',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'text',
                type => 'const char *'
              },
              {
                declaration_name => 'size',
                type => 'const char *'
              }
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'saveData',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Information of game state. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Stores what entries are available to the player '
                }
              ]
            },
            type => 'explorerData'
          },
          {
            kind => 'variable',
            name => 'items',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Explorer items to be rendered. '
                }
              ]
            },
            detailed => {},
            type => 'std::vector< std::pair< SDL_Texture *, SDL_Rect > >'
          },
          {
            kind => 'variable',
            name => 'background',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Background of explorer. '
                }
              ]
            },
            detailed => {},
            type => 'SDL_Texture *'
          },
          {
            kind => 'variable',
            name => 'nameWrapLength',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Maximum length of the name in texture. '
                }
              ]
            },
            detailed => {},
            type => 'const int'
          },
          {
            kind => 'variable',
            name => 'downloadBounds',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Position of the download button. '
                }
              ]
            },
            detailed => {},
            type => 'const SDL_Rect'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'game',
      kind => 'class',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'game.hh'
      },
      all_members => [
        {
          name => 'bgm',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'game'
        },
        {
          name => 'dispBounds',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'game'
        },
        {
          name => 'font',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'game'
        },
        {
          name => 'game',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'game'
        },
        {
          name => 'gameplay',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'game'
        },
        {
          name => 'gameState',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'game'
        },
        {
          name => 'loadThread',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'game'
        },
        {
          name => 'mainRenderer',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'game'
        },
        {
          name => 'mainWindow',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'game'
        },
        {
          name => 'mutex',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'game'
        },
        {
          name => 'pixelSize',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'game'
        },
        {
          name => 'silence',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'game'
        },
        {
          name => 'state',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'game'
        },
        {
          name => 'winMan',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'game'
        },
        {
          name => '~game',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'game'
        }
      ],
      public_typedefs => {
        members => [
          {
            kind => 'enum',
            name => 'gameState',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint8_t',
            values => [
              {
                name => 'terminating',
                brief => {},
                detailed => {}
              },
              {
                name => 'intro',
                brief => {},
                detailed => {}
              },
              {
                name => 'gameplay',
                brief => {},
                detailed => {}
              },
              {
                name => 'paused',
                brief => {},
                detailed => {}
              }
            ]
          }
        ]
      },
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'game',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a new game object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'WM will be loaded in a thread. '
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => '~game',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Destroy the game object. '
                }
              ]
            },
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'gameplay',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Runs the WM. Waits for the WM to be initialised, first. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'state',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'State that the game is in. '
                }
              ]
            },
            detailed => {},
            type => 'gameState',
            initializer => '= gameState::intro'
          },
          {
            kind => 'variable',
            name => 'dispBounds',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Rect containing the screen height and width. '
                }
              ]
            },
            detailed => {},
            type => 'SDL_Rect'
          },
          {
            kind => 'variable',
            name => 'mainWindow',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Main window to render to. '
                }
              ]
            },
            detailed => {},
            type => 'SDL_Window *'
          },
          {
            kind => 'variable',
            name => 'mainRenderer',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Main renderer that renders to mainWindow. '
                }
              ]
            },
            detailed => {},
            type => 'SDL_Renderer *'
          },
          {
            kind => 'variable',
            name => 'bgm',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Background music. Randomly selected. '
                }
              ]
            },
            detailed => {},
            type => 'std::array< Mix_Music *, 4 >'
          },
          {
            kind => 'variable',
            name => 'silence',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Different lengths of silence. Randomly selected. '
                }
              ]
            },
            detailed => {},
            type => 'std::array< Mix_Music *, 6 >'
          },
          {
            kind => 'variable',
            name => 'font',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Font used for text. '
                }
              ]
            },
            detailed => {},
            type => 'TTF_Font *'
          },
          {
            kind => 'variable',
            name => 'pixelSize',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Size of virtual pixels per real pixel. '
                },
                {
                  type => 'linebreak'
                },
                {
                  type => 'text',
                  content => ' '
                }
              ]
            },
            type => 'double'
          },
          {
            kind => 'variable',
            name => 'winMan',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Windows manager. '
                }
              ]
            },
            detailed => {},
            type => 'wm'
          },
          {
            kind => 'variable',
            name => 'mutex',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'SDL_mutex *'
          },
          {
            kind => 'variable',
            name => 'loadThread',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Thread that loads winMan. '
                }
              ]
            },
            detailed => {},
            type => 'SDL_Thread *'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'intro_t',
      kind => 'class',
      base => [
        {
          name => 'scene',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
        {
          name => 'intro_t::slide'
        }
      ],
      includes => {
        local => 'no',
        name => 'init.hh'
      },
      all_members => [
        {
          name => 'addSlide',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'intro_t'
        },
        {
          name => 'centre',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'intro_t'
        },
        {
          name => 'centreRect',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'intro_t'
        },
        {
          name => 'context',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'handle',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'intro_t'
        },
        {
          name => 'intro_t',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'intro_t'
        },
        {
          name => 'loadTexture',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'render',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'intro_t'
        },
        {
          name => 'scene',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'skip',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'intro_t'
        },
        {
          name => 'slides',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'intro_t'
        },
        {
          name => 'slideShow',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'intro_t'
        },
        {
          name => 'startTime',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'intro_t'
        },
        {
          name => 'update',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'intro_t'
        },
        {
          name => '~intro_t',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'intro_t'
        },
        {
          name => '~scene',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'scene'
        }
      ],
      public_typedefs => {
        members => [
          {
            kind => 'enum',
            name => 'centre',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'uint8_t',
            values => [
              {
                name => 'HORIZONTAL',
                brief => {},
                detailed => {}
              },
              {
                name => 'VERTICAL',
                brief => {},
                detailed => {}
              },
              {
                name => 'BOTH',
                brief => {},
                detailed => {}
              }
            ]
          }
        ]
      },
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'intro_t',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a new intro t object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Called only once when WM is initialised'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'context'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Game context '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'context',
                type => 'game *'
              }
            ]
          },
          {
            kind => 'function',
            name => '~intro_t',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Destroy the intro t object. '
                }
              ]
            },
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'update',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Updates scene info. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Makes the call on when to move on to explorer.'
                },
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'When it moves on, it calls its own destructor to minimise its size and effect on memory usage.'
                },
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'std::pair<scenes, sceneData> Returns the scene to be changed to, and the data that scene should contain '
                    }
                  ]
                }
              ]
            },
            type => 'std::pair< scenes, sceneData >',
            const => 'no',
            volatile => 'no',
            parameters => [
            ],
            reimplements => {
              name => 'update'
            }
          },
          {
            kind => 'function',
            name => 'render',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Renders slides. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ],
            reimplements => {
              name => 'render'
            }
          },
          {
            kind => 'function',
            name => 'handle',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'event'
                        }
                      ],
                      doc => [
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'std::pair<scenes, sceneData> '
                    }
                  ]
                }
              ]
            },
            type => 'std::pair< scenes, sceneData >',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'event',
                type => 'const SDL_Event &'
              }
            ],
            reimplements => {
              name => 'handle'
            }
          },
          {
            kind => 'function',
            name => 'slideShow',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Performs the slideshow logic. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'time'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Current time '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'click'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Whether a click happened in the past n seconds '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'skipGrace'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Grace period for skipping. Default: 500 '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'time',
                type => 'size_t'
              },
              {
                declaration_name => 'click',
                type => 'bool &'
              },
              {
                declaration_name => 'skipGrace',
                type => 'size_t',
                default_value => '500'
              }
            ]
          },
          {
            kind => 'function',
            name => 'addSlide',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Adds slides to slideshow. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'surface'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Surface to be converted into a slideshow. Will be converted into a texture, then freed. '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'fadeIn'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Fade in duration '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'duration'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Full brightness duration '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'fadeOut'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Fade out duration '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'dest'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Destination for where to render the slide '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'centred'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Whether the slide is centred. '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'skippable'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Whether it is permissible to skip the slide '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'surface',
                type => 'SDL_Surface *'
              },
              {
                declaration_name => 'fadeIn',
                type => 'size_t'
              },
              {
                declaration_name => 'duration',
                type => 'size_t'
              },
              {
                declaration_name => 'fadeOut',
                type => 'size_t'
              },
              {
                declaration_name => 'dest',
                type => 'SDL_Rect',
                default_value => 'SDL_Rect{}'
              },
              {
                declaration_name => 'centred',
                type => 'bool',
                default_value => 'true'
              },
              {
                declaration_name => 'skippable',
                type => 'bool',
                default_value => 'true'
              }
            ]
          },
          {
            kind => 'function',
            name => 'centreRect',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Centres rect. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'rect'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Rect to centre '
                        }
                      ]
                    },
                    {
                      parameters => [
                        {
                          name => 'centre'
                        }
                      ],
                      doc => [
                        {
                          type => 'parbreak'
                        },
                        {
                          type => 'text',
                          content => 'Stores how the rect will be centred '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            type => 'void',
            const => 'yes',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'rect',
                type => 'SDL_Rect &'
              },
              {
                declaration_name => 'centre',
                type => 'centre',
                default_value => 'centre::BOTH'
              }
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'slides',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Slides to be slideshowed. '
                }
              ]
            },
            detailed => {},
            type => 'std::vector< slide >'
          },
          {
            kind => 'variable',
            name => 'startTime',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The time at which each slide starts. '
                }
              ]
            },
            detailed => {},
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'skip',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Whether a skip is requested by the event handler. '
                }
              ]
            },
            detailed => {},
            type => 'bool'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'notepad_t',
      kind => 'class',
      base => [
        {
          name => 'scene',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'notepad.hh'
      },
      all_members => [
        {
          name => 'background',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'notepad_t'
        },
        {
          name => 'context',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'currentData',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'notepad_t'
        },
        {
          name => 'entry',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'notepad_t'
        },
        {
          name => 'entryRect',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'notepad_t'
        },
        {
          name => 'handle',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'notepad_t'
        },
        {
          name => 'lineWrapLength',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'notepad_t'
        },
        {
          name => 'loadTexture',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'notepad_t',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'notepad_t'
        },
        {
          name => 'prevData',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'notepad_t'
        },
        {
          name => 'render',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'notepad_t'
        },
        {
          name => 'scale',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'notepad_t'
        },
        {
          name => 'scene',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'update',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'notepad_t'
        },
        {
          name => '~notepad_t',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'notepad_t'
        },
        {
          name => '~scene',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'scene'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'notepad_t',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a new notepad t object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Called only once when WM is initialised'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'context'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'game context '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'context',
                type => 'game *'
              }
            ]
          },
          {
            kind => 'function',
            name => '~notepad_t',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Destroy the notepad t object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Called only when the wm is destroyed '
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'update',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Checks if the current data is the same as the data stored previously. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Does nothing if it\'s the same.'
                },
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'std::pair<scenes, sceneData> '
                    }
                  ]
                }
              ]
            },
            type => 'std::pair< scenes, sceneData >',
            const => 'no',
            volatile => 'no',
            parameters => [
            ],
            reimplements => {
              name => 'update'
            }
          },
          {
            kind => 'function',
            name => 'render',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Renders notepad, and entry. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ],
            reimplements => {
              name => 'render'
            }
          },
          {
            kind => 'function',
            name => 'handle',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Handles event. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Realistically, does nothing unless I add scrolling.'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'event'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Event to be handled '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'std::pair<scenes, sceneData> Returns the scene to be changed to, and the data that scene should contain '
                    }
                  ]
                }
              ]
            },
            type => 'std::pair< scenes, sceneData >',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'event',
                type => 'const SDL_Event &'
              }
            ],
            reimplements => {
              name => 'handle'
            }
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'background',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Background of the notepad as a texture. '
                }
              ]
            },
            detailed => {},
            type => 'SDL_Texture *'
          },
          {
            kind => 'variable',
            name => 'entry',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Text of the notepad, as a texture. '
                }
              ]
            },
            detailed => {},
            type => 'SDL_Texture *'
          },
          {
            kind => 'variable',
            name => 'lineWrapLength',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Length before the note wraps the length. '
                }
              ]
            },
            detailed => {},
            type => 'const int'
          },
          {
            kind => 'variable',
            name => 'currentData',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The current entry. '
                }
              ]
            },
            detailed => {},
            type => 'notepadData'
          },
          {
            kind => 'variable',
            name => 'prevData',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The last entry that was there when notepad was exited. '
                }
              ]
            },
            detailed => {},
            type => 'notepadData'
          },
          {
            kind => 'variable',
            name => 'entryRect',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Position of the entry. '
                }
              ]
            },
            detailed => {},
            type => 'SDL_Rect'
          }
        ]
      },
      public_static_members => {
        members => [
          {
            kind => 'variable',
            name => 'scale',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'yes',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'The multiplier by which the text is scaled '
                },
                {
                  type => 'style',
                  style => 'bold',
                  enable => 'yes'
                },
                {
                  type => 'text',
                  content => 'down'
                },
                {
                  type => 'style',
                  style => 'bold',
                  enable => 'no'
                },
                {
                  type => 'text',
                  content => ' '
                }
              ]
            },
            detailed => {},
            type => 'static constexpr double',
            initializer => '= 1.7'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'pause_t',
      kind => 'class',
      base => [
        {
          name => 'scene',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'pause.hh'
      },
      all_members => [
        {
          name => 'context',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'exit',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'pause_t'
        },
        {
          name => 'exitHover',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'pause_t'
        },
        {
          name => 'exitPos',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'pause_t'
        },
        {
          name => 'exitState',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'pause_t'
        },
        {
          name => 'handle',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'pause_t'
        },
        {
          name => 'loadTexture',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'overlay',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'pause_t'
        },
        {
          name => 'pause_t',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'pause_t'
        },
        {
          name => 'render',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'pause_t'
        },
        {
          name => 'resume',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'pause_t'
        },
        {
          name => 'resumeHover',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'pause_t'
        },
        {
          name => 'resumePos',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'pause_t'
        },
        {
          name => 'resumeState',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'pause_t'
        },
        {
          name => 'scene',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'update',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'pause_t'
        },
        {
          name => '~pause_t',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'pause_t'
        },
        {
          name => '~scene',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'scene'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'pause_t',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a new pause t object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Called only once when WM is initialised'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'context'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'game context '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'context',
                type => 'game *'
              }
            ]
          },
          {
            kind => 'function',
            name => '~pause_t',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Destroy the pause t object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Called only when the wm is destroyed '
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'update',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Update logic for the pause menu. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Realistically, does absolutely nothing.'
                },
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'std::pair<scenes, sceneData> Returns the scene to be changed to, and the data that scene should contain '
                    }
                  ]
                }
              ]
            },
            type => 'std::pair< scenes, sceneData >',
            const => 'no',
            volatile => 'no',
            parameters => [
            ],
            reimplements => {
              name => 'update'
            }
          },
          {
            kind => 'function',
            name => 'render',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Renders menu, and buttons. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ],
            reimplements => {
              name => 'render'
            }
          },
          {
            kind => 'function',
            name => 'handle',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Handles hovers. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'event'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Event to be handled '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'std::pair<scenes, sceneData>Returns the scene to be changed to, and the data that scene should contain '
                    }
                  ]
                }
              ]
            },
            type => 'std::pair< scenes, sceneData >',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'event',
                type => 'const SDL_Event &'
              }
            ],
            reimplements => {
              name => 'handle'
            }
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'overlay',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Pause overlay. '
                }
              ]
            },
            detailed => {},
            type => 'SDL_Texture *'
          },
          {
            kind => 'variable',
            name => 'resume',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Resume button when not hovered. '
                }
              ]
            },
            detailed => {},
            type => 'SDL_Texture *'
          },
          {
            kind => 'variable',
            name => 'resumeHover',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Resume button when hovered over. '
                }
              ]
            },
            detailed => {},
            type => 'SDL_Texture *'
          },
          {
            kind => 'variable',
            name => 'resumeState',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'State of the resume button. '
                }
              ]
            },
            detailed => {},
            type => 'SDL_Texture *'
          },
          {
            kind => 'variable',
            name => 'resumePos',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Position of the resume button '
                }
              ]
            },
            type => 'SDL_Rect'
          },
          {
            kind => 'variable',
            name => 'exit',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Exit button when not hovered. '
                }
              ]
            },
            detailed => {},
            type => 'SDL_Texture *'
          },
          {
            kind => 'variable',
            name => 'exitHover',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Exit button when hovered over. '
                }
              ]
            },
            detailed => {},
            type => 'SDL_Texture *'
          },
          {
            kind => 'variable',
            name => 'exitState',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'State of the exit button. '
                }
              ]
            },
            detailed => {},
            type => 'SDL_Texture *'
          },
          {
            kind => 'variable',
            name => 'exitPos',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Position of the exit button. '
                }
              ]
            },
            detailed => {},
            type => 'SDL_Rect'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'scene',
      kind => 'class',
      derived => [
        {
          name => 'explorer_t',
          virtualness => 'non_virtual',
          protection => 'public'
        },
        {
          name => 'intro_t',
          virtualness => 'non_virtual',
          protection => 'public'
        },
        {
          name => 'notepad_t',
          virtualness => 'non_virtual',
          protection => 'public'
        },
        {
          name => 'pause_t',
          virtualness => 'non_virtual',
          protection => 'public'
        },
        {
          name => 'shitcord_t',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'scene.hh'
      },
      all_members => [
        {
          name => 'context',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'handle',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'loadTexture',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'render',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'scene',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'update',
          virtualness => 'pure_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => '~scene',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'scene'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'loadTexture',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Loads texture based on path. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'path'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'File path '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL_Texture* Loaded texture '
                    }
                  ]
                }
              ]
            },
            type => 'SDL_Texture *',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'path',
                type => 'const char *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'scene',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a new scene object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'gameContext'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'game context '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'gameContext',
                type => 'const game *'
              }
            ]
          },
          {
            kind => 'function',
            name => '~scene',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Destroy the scene object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Usually called only when wm is destroyed '
                }
              ]
            },
            type => 'virtual',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'update',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Updates scene logic. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Called in '
                },
                {
                  type => 'url',
                  link => 'df/d1c/classwm_1a54115bce16818acb350825256b11b2ce',
                  content => 'wm::update()'
                },
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'std::pair<scenes, sceneData> Returns the scene to be changed to, and the data that scene should contain '
                    }
                  ]
                }
              ]
            },
            type => 'virtual std::pair< scenes, sceneData >',
            const => 'no',
            volatile => 'no',
            parameters => [
            ],
            reimplemented_by => [
              {
                name => 'update'
              },
              {
                name => 'update'
              },
              {
                name => 'update'
              },
              {
                name => 'update'
              },
              {
                name => 'update'
              }
            ]
          },
          {
            kind => 'function',
            name => 'render',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Renders textures. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Called in '
                },
                {
                  type => 'url',
                  link => 'df/d1c/classwm_1aa9731642bc561de498bc559f0d5ab84e',
                  content => 'wm::render()'
                },
                {
                  type => 'text',
                  content => ' '
                }
              ]
            },
            type => 'virtual void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ],
            reimplemented_by => [
              {
                name => 'render'
              },
              {
                name => 'render'
              },
              {
                name => 'render'
              },
              {
                name => 'render'
              },
              {
                name => 'render'
              }
            ]
          },
          {
            kind => 'function',
            name => 'handle',
            virtualness => 'pure_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Handles events. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Called in '
                },
                {
                  type => 'url',
                  link => 'df/d1c/classwm_1a08290ca96dc53c185d114f2beae1f7a6',
                  content => 'wm::handle()'
                },
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'std::pair<scenes, sceneData> Returns the scene to be changed to, and the data that scene should contain '
                    }
                  ]
                }
              ]
            },
            type => 'virtual std::pair< scenes, sceneData >',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                type => 'const SDL_Event &'
              }
            ],
            reimplemented_by => [
              {
                name => 'handle'
              },
              {
                name => 'handle'
              },
              {
                name => 'handle'
              },
              {
                name => 'handle'
              },
              {
                name => 'handle'
              }
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'context',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Game context. '
                }
              ]
            },
            detailed => {},
            type => 'const game *'
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'Interface class for scenes. '
          }
        ]
      },
      detailed => {}
    },
    {
      name => 'shitcord_t',
      kind => 'class',
      base => [
        {
          name => 'scene',
          virtualness => 'non_virtual',
          protection => 'public'
        }
      ],
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'shitcord.hh'
      },
      all_members => [
        {
          name => 'background',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'shitcord_t'
        },
        {
          name => 'context',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'generateOptions',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'shitcord_t'
        },
        {
          name => 'handle',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'shitcord_t'
        },
        {
          name => 'loadTexture',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'render',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'shitcord_t'
        },
        {
          name => 'scene',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => 'shitcord_t',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'shitcord_t'
        },
        {
          name => 'update',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'shitcord_t'
        },
        {
          name => '~scene',
          virtualness => 'virtual',
          protection => 'public',
          scope => 'scene'
        },
        {
          name => '~shitcord_t',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'shitcord_t'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'shitcord_t',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a new shitcord t object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Called only once when WM is initialised'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'context'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'game context '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'context',
                type => 'const game *'
              }
            ]
          },
          {
            kind => 'function',
            name => '~shitcord_t',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Destroy the shitcord t object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Called only when the wm is destroyed '
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'update',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Update logic for shitcord. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Probably does the message appearing'
                },
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'std::pair<scenes, sceneData> Returns the scene to be changed to, and the data that scene should contain '
                    }
                  ]
                }
              ]
            },
            type => 'std::pair< scenes, sceneData >',
            const => 'no',
            volatile => 'no',
            parameters => [
            ],
            reimplements => {
              name => 'update'
            }
          },
          {
            kind => 'function',
            name => 'render',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Renders menu, and messages. '
                }
              ]
            },
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ],
            reimplements => {
              name => 'render'
            }
          },
          {
            kind => 'function',
            name => 'handle',
            virtualness => 'virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Handles hovers. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'event'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Event to be handled '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'std::pair<scenes, sceneData>Returns the scene to be changed to, and the data that scene should contain '
                    }
                  ]
                }
              ]
            },
            type => 'std::pair< scenes, sceneData >',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'event',
                type => 'const SDL_Event &'
              }
            ],
            reimplements => {
              name => 'handle'
            }
          },
          {
            kind => 'function',
            name => 'generateOptions',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Generates the option texture from the surface. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'options'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Options to be enumerated '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'SDL_Texture* Texture, upscaled by a factor of 2. '
                    }
                  ]
                }
              ]
            },
            type => 'SDL_Texture *',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'options',
                type => 'const std::array< std::string, 3 >'
              }
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'background',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'SDL_Texture *'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'intro_t::slide',
      kind => 'class',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'init.hh'
      },
      all_members => [
        {
          name => 'dest',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'intro_t::slide'
        },
        {
          name => 'duration',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'intro_t::slide'
        },
        {
          name => 'fadeIn',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'intro_t::slide'
        },
        {
          name => 'fadeOut',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'intro_t::slide'
        },
        {
          name => 'skippable',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'intro_t::slide'
        },
        {
          name => 'slide',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'intro_t::slide'
        },
        {
          name => 'texture',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'intro_t::slide'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'slide',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => '_fadeIn',
                type => 'size_t'
              },
              {
                declaration_name => '_fadeOut',
                type => 'size_t'
              },
              {
                declaration_name => '_duration',
                type => 'size_t'
              },
              {
                declaration_name => '_texture',
                type => 'SDL_Texture *'
              },
              {
                declaration_name => '_dest',
                type => 'SDL_Rect',
                default_value => '{}'
              },
              {
                declaration_name => 'skippable',
                type => 'bool',
                default_value => 'true'
              }
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'fadeIn',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'duration',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'fadeOut',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'size_t'
          },
          {
            kind => 'variable',
            name => 'texture',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'SDL_Texture *'
          },
          {
            kind => 'variable',
            name => 'dest',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'SDL_Rect'
          },
          {
            kind => 'variable',
            name => 'skippable',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'bool'
          }
        ]
      },
      brief => {
        doc => [
          {
            type => 'parbreak'
          },
          {
            type => 'text',
            content => 'Contains all the information required for a functional slideshow. '
          }
        ]
      },
      detailed => {}
    },
    {
      name => 'wm',
      kind => 'class',
      inner => [
      ],
      includes => {
        local => 'no',
        name => 'wm.hh'
      },
      all_members => [
        {
          name => 'context',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wm'
        },
        {
          name => 'current',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wm'
        },
        {
          name => 'explorer',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wm'
        },
        {
          name => 'handle',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wm'
        },
        {
          name => 'icons',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wm'
        },
        {
          name => 'intro',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wm'
        },
        {
          name => 'notepad',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wm'
        },
        {
          name => 'OSOverlay',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wm'
        },
        {
          name => 'pause',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wm'
        },
        {
          name => 'pauseBounds',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wm'
        },
        {
          name => 'render',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wm'
        },
        {
          name => 'resume',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wm'
        },
        {
          name => 'shitcord',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wm'
        },
        {
          name => 'update',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wm'
        },
        {
          name => 'wasSilence',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wm'
        },
        {
          name => 'wm',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wm'
        },
        {
          name => 'wm',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wm'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'wm',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a new wm object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Just to placate the warnings '
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'wm',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Construct a new wm object. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Constructs all the scenes, too'
                },
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'context'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'game context '
                        }
                      ]
                    }
                  ]
                }
              ]
            },
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'context',
                type => 'game *'
              }
            ]
          },
          {
            kind => 'function',
            name => 'render',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Renders the current scene, icons, and the overlay. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Does not render if the current scene is the intro. '
                }
              ]
            },
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'handle',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Handles events and scene switches via task bar. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  params => [
                    {
                      parameters => [
                        {
                          name => 'event'
                        }
                      ],
                      doc => [
                        {
                          type => 'text',
                          content => 'Event to be handled. '
                        }
                      ]
                    }
                  ]
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'std::pair<scenes, sceneData> Returns the scene to be changed to, and the data that scene should contain '
                    }
                  ]
                }
              ]
            },
            type => 'std::pair< scenes, sceneData >',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'event',
                type => 'const SDL_Event &'
              }
            ]
          },
          {
            kind => 'function',
            name => 'update',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Updates scene data. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  return => [
                    {
                      type => 'text',
                      content => 'std::pair<scenes, sceneData> Returns the scene to be changed to, and the data that scene should contain '
                    }
                  ]
                }
              ]
            },
            type => 'std::pair< scenes, sceneData >',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'icons',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Icons for the task bar. '
                }
              ]
            },
            detailed => {},
            type => 'std::vector< std::pair< SDL_Texture *, SDL_Rect > >'
          },
          {
            kind => 'variable',
            name => 'OSOverlay',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Task bar overlay. '
                }
              ]
            },
            detailed => {},
            type => 'SDL_Texture *'
          },
          {
            kind => 'variable',
            name => 'context',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'game context '
                }
              ]
            },
            detailed => {},
            type => 'game *'
          },
          {
            kind => 'variable',
            name => 'pauseBounds',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Position of the pause button. '
                }
              ]
            },
            detailed => {},
            type => 'SDL_Rect'
          },
          {
            kind => 'variable',
            name => 'wasSilence',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Stores whether the last music track was silent. '
                }
              ]
            },
            detailed => {},
            type => 'bool',
            initializer => '= 0'
          },
          {
            kind => 'variable',
            name => 'explorer',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Scenes. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Unique pointers so that they\'ll kill themselves once wm terminates '
                }
              ]
            },
            type => 'std::unique_ptr< explorer_t >'
          },
          {
            kind => 'variable',
            name => 'notepad',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::unique_ptr< notepad_t >'
          },
          {
            kind => 'variable',
            name => 'pause',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::unique_ptr< pause_t >'
          },
          {
            kind => 'variable',
            name => 'intro',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::unique_ptr< intro_t >'
          },
          {
            kind => 'variable',
            name => 'shitcord',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::unique_ptr< shitcord_t >'
          },
          {
            kind => 'variable',
            name => 'current',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Current scene. '
                }
              ]
            },
            detailed => {},
            type => 'scene *'
          },
          {
            kind => 'variable',
            name => 'resume',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Scene to resume on. Only used for unpausing purposes. '
                }
              ]
            },
            detailed => {},
            type => 'scene *'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'wmInitData',
      kind => 'struct',
      inner => [
      ],
      all_members => [
        {
          name => 'context',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wmInitData'
        },
        {
          name => 'lock',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wmInitData'
        },
        {
          name => 'mutex',
          virtualness => 'non_virtual',
          protection => 'private',
          scope => 'wmInitData'
        },
        {
          name => 'unlock',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wmInitData'
        },
        {
          name => 'winMan',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wmInitData'
        },
        {
          name => 'wmInitData',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wmInitData'
        },
        {
          name => '~wmInitData',
          virtualness => 'non_virtual',
          protection => 'public',
          scope => 'wmInitData'
        }
      ],
      public_methods => {
        members => [
          {
            kind => 'function',
            name => 'wmInitData',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => '_winMan',
                type => 'wm *'
              },
              {
                declaration_name => '_context',
                type => 'game *'
              },
              {
                declaration_name => '_mutex',
                type => 'SDL_mutex *'
              }
            ]
          },
          {
            kind => 'function',
            name => '~wmInitData',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'lock',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          },
          {
            kind => 'function',
            name => 'unlock',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'void',
            const => 'no',
            volatile => 'no',
            parameters => [
            ]
          }
        ]
      },
      public_members => {
        members => [
          {
            kind => 'variable',
            name => 'winMan',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'wm *'
          },
          {
            kind => 'variable',
            name => 'context',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'game *'
          }
        ]
      },
      private_members => {
        members => [
          {
            kind => 'variable',
            name => 'mutex',
            virtualness => 'non_virtual',
            protection => 'private',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'SDL_mutex *'
          }
        ]
      },
      brief => {},
      detailed => {}
    }
  ],
  concepts => [
  ],
  modules => [
  ],
  namespaces => [
  ],
  files => [
    {
      name => 'enum.hh',
      includes => [
        {
          name => 'cstdint'
        },
        {
          name => 'variant'
        }
      ],
      included_by => [
        {
          name => 'include/scenes/scene.hh',
          ref => 'd5/dd8/scene_8hh'
        },
        {
          name => 'include/wm.hh',
          ref => 'd3/d51/wm_8hh'
        },
        {
          name => 'src/game/gameplay.cc',
          ref => 'de/d8a/gameplay_8cc'
        }
      ],
      typedefs => {
        members => [
          {
            kind => 'typedef',
            name => 'sceneData',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'std::variant< std::monostate, notepadData >',
            initializer => ' std::variant<std::monostate, notepadData>'
          }
        ]
      },
      enums => {
        members => [
          {
            kind => 'enum',
            name => 'notepadData',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Entry currently stored in notepad. '
                }
              ]
            },
            detailed => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Enumerated continuously and in order to make file name queries convenient '
                }
              ]
            },
            type => 'uint8_t',
            values => [
              {
                name => 'empty',
                brief => {},
                detailed => {}
              },
              {
                name => 'entry1',
                initializer => '= 1',
                brief => {},
                detailed => {}
              },
              {
                name => 'entry2',
                initializer => '= 2',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'explorerData',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Entries list. '
                }
              ]
            },
            detailed => {},
            type => 'uint8_t',
            values => [
              {
                name => 'init',
                brief => {},
                detailed => {}
              },
              {
                name => 'entry1',
                brief => {},
                detailed => {}
              },
              {
                name => 'entry2',
                brief => {},
                detailed => {}
              },
              {
                name => 'size',
                brief => {},
                detailed => {}
              }
            ]
          },
          {
            kind => 'enum',
            name => 'scenes',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {
              doc => [
                {
                  type => 'parbreak'
                },
                {
                  type => 'text',
                  content => 'Scenes list. '
                }
              ]
            },
            detailed => {},
            type => 'uint8_t',
            values => [
              {
                name => 'intro',
                brief => {},
                detailed => {}
              },
              {
                name => 'explorer',
                brief => {},
                detailed => {}
              },
              {
                name => 'notepad',
                brief => {},
                detailed => {}
              },
              {
                name => 'pause',
                brief => {},
                detailed => {}
              },
              {
                name => 'shitcord',
                brief => {},
                detailed => {}
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'game.hh',
      includes => [
        {
          name => 'array'
        },
        {
          name => 'SDL.h'
        },
        {
          name => 'SDL_mixer.h'
        },
        {
          name => 'SDL_ttf.h'
        },
        {
          name => 'wm.hh',
          ref => 'd3/d51/wm_8hh'
        }
      ],
      included_by => [
        {
          name => 'src/game/gameplay.cc',
          ref => 'de/d8a/gameplay_8cc'
        },
        {
          name => 'src/game/pause.cc',
          ref => 'df/d0b/pause_8cc'
        },
        {
          name => 'src/game/wm.cc',
          ref => 'df/d17/wm_8cc'
        },
        {
          name => 'src/main.cc',
          ref => 'd9/d0f/main_8cc'
        },
        {
          name => 'src/scenes/explorer.cc',
          ref => 'd5/d14/explorer_8cc'
        },
        {
          name => 'src/scenes/init.cc',
          ref => 'd0/ddc/init_8cc'
        },
        {
          name => 'src/scenes/notepad.cc',
          ref => 'd0/d31/notepad_8cc'
        },
        {
          name => 'src/scenes/scene.cc',
          ref => 'd4/d11/scene_8cc'
        },
        {
          name => 'src/scenes/shitcord.cc',
          ref => 'd0/dd7/shitcord_8cc'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'explorer.hh',
      includes => [
        {
          name => 'scene.hh',
          ref => 'd5/dd8/scene_8hh'
        }
      ],
      included_by => [
        {
          name => 'include/wm.hh',
          ref => 'd3/d51/wm_8hh'
        },
        {
          name => 'src/game/wm.cc',
          ref => 'df/d17/wm_8cc'
        },
        {
          name => 'src/scenes/explorer.cc',
          ref => 'd5/d14/explorer_8cc'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'init.hh',
      includes => [
        {
          name => 'scene.hh',
          ref => 'd5/dd8/scene_8hh'
        }
      ],
      included_by => [
        {
          name => 'include/wm.hh',
          ref => 'd3/d51/wm_8hh'
        },
        {
          name => 'src/game/wm.cc',
          ref => 'df/d17/wm_8cc'
        },
        {
          name => 'src/scenes/init.cc',
          ref => 'd0/ddc/init_8cc'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'notepad.hh',
      includes => [
        {
          name => '../scenes/scene.hh',
          ref => 'd5/dd8/scene_8hh'
        }
      ],
      included_by => [
        {
          name => 'include/wm.hh',
          ref => 'd3/d51/wm_8hh'
        },
        {
          name => 'src/game/wm.cc',
          ref => 'df/d17/wm_8cc'
        },
        {
          name => 'src/scenes/notepad.cc',
          ref => 'd0/d31/notepad_8cc'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'pause.hh',
      includes => [
        {
          name => 'scene.hh',
          ref => 'd5/dd8/scene_8hh'
        }
      ],
      included_by => [
        {
          name => 'include/wm.hh',
          ref => 'd3/d51/wm_8hh'
        },
        {
          name => 'src/game/pause.cc',
          ref => 'df/d0b/pause_8cc'
        },
        {
          name => 'src/game/wm.cc',
          ref => 'df/d17/wm_8cc'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'scene.hh',
      includes => [
        {
          name => 'utility'
        },
        {
          name => 'SDL.h'
        },
        {
          name => 'enum.hh',
          ref => 'd9/d05/enum_8hh'
        }
      ],
      included_by => [
        {
          name => 'include/scenes/explorer.hh',
          ref => 'd4/d7c/explorer_8hh'
        },
        {
          name => 'include/scenes/init.hh',
          ref => 'dd/d82/init_8hh'
        },
        {
          name => 'include/scenes/notepad.hh',
          ref => 'd4/d54/notepad_8hh'
        },
        {
          name => 'include/scenes/pause.hh',
          ref => 'd4/d90/pause_8hh'
        },
        {
          name => 'include/scenes/shitcord.hh',
          ref => 'd1/da8/shitcord_8hh'
        },
        {
          name => 'src/scenes/scene.cc',
          ref => 'd4/d11/scene_8cc'
        }
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'pix',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            parameters => [
              {
                name => 'val'
              }
            ],
            initializer => 'static_cast<int>(val * context->pixelSize)'
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'shitcord.hh',
      includes => [
        {
          name => 'array'
        },
        {
          name => 'string'
        },
        {
          name => 'scene.hh',
          ref => 'd5/dd8/scene_8hh'
        }
      ],
      included_by => [
        {
          name => 'include/wm.hh',
          ref => 'd3/d51/wm_8hh'
        },
        {
          name => 'src/game/wm.cc',
          ref => 'df/d17/wm_8cc'
        },
        {
          name => 'src/scenes/shitcord.cc',
          ref => 'd0/dd7/shitcord_8cc'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'wm.hh',
      includes => [
        {
          name => 'memory'
        },
        {
          name => 'vector'
        },
        {
          name => 'SDL.h'
        },
        {
          name => 'enum.hh',
          ref => 'd9/d05/enum_8hh'
        },
        {
          name => 'scenes/explorer.hh',
          ref => 'd4/d7c/explorer_8hh'
        },
        {
          name => 'scenes/init.hh',
          ref => 'dd/d82/init_8hh'
        },
        {
          name => 'scenes/notepad.hh',
          ref => 'd4/d54/notepad_8hh'
        },
        {
          name => 'scenes/pause.hh',
          ref => 'd4/d90/pause_8hh'
        },
        {
          name => 'scenes/shitcord.hh',
          ref => 'd1/da8/shitcord_8hh'
        }
      ],
      included_by => [
        {
          name => 'include/game.hh',
          ref => 'd3/d0e/game_8hh'
        },
        {
          name => 'src/game/gameplay.cc',
          ref => 'de/d8a/gameplay_8cc'
        },
        {
          name => 'src/game/wm.cc',
          ref => 'df/d17/wm_8cc'
        }
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'game.cc',
      includes => [
        {
          name => '../include/game.hh'
        },
        {
          name => 'iostream'
        }
      ],
      included_by => [
      ],
      functions => {
        members => [
          {
            kind => 'function',
            name => 'wmInit',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'data',
                type => 'void *'
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'gameplay.cc',
      includes => [
        {
          name => 'game.hh',
          ref => 'd3/d0e/game_8hh'
        },
        {
          name => 'wm.hh',
          ref => 'd3/d51/wm_8hh'
        },
        {
          name => 'enum.hh',
          ref => 'd9/d05/enum_8hh'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'pause.cc',
      includes => [
        {
          name => 'scenes/pause.hh',
          ref => 'd4/d90/pause_8hh'
        },
        {
          name => 'game.hh',
          ref => 'd3/d0e/game_8hh'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'wm.cc',
      includes => [
        {
          name => 'wm.hh',
          ref => 'd3/d51/wm_8hh'
        },
        {
          name => 'iostream'
        },
        {
          name => 'SDL_image.h'
        },
        {
          name => 'game.hh',
          ref => 'd3/d0e/game_8hh'
        },
        {
          name => 'scenes/explorer.hh',
          ref => 'd4/d7c/explorer_8hh'
        },
        {
          name => 'scenes/init.hh',
          ref => 'dd/d82/init_8hh'
        },
        {
          name => 'scenes/notepad.hh',
          ref => 'd4/d54/notepad_8hh'
        },
        {
          name => 'scenes/pause.hh',
          ref => 'd4/d90/pause_8hh'
        },
        {
          name => 'scenes/shitcord.hh',
          ref => 'd1/da8/shitcord_8hh'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'main.cc',
      includes => [
        {
          name => 'iostream'
        },
        {
          name => 'SDL.h'
        },
        {
          name => 'SDL_image.h'
        },
        {
          name => 'SDL_mixer.h'
        },
        {
          name => 'SDL_ttf.h'
        },
        {
          name => 'game.hh',
          ref => 'd3/d0e/game_8hh'
        }
      ],
      included_by => [
      ],
      defines => {
        members => [
          {
            kind => 'define',
            name => 'skipIntro',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {}
          }
        ]
      },
      functions => {
        members => [
          {
            kind => 'function',
            name => 'main',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'int',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'argc',
                type => 'int'
              },
              {
                declaration_name => 'argv',
                type => 'char **'
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'explorer.cc',
      includes => [
        {
          name => 'scenes/explorer.hh',
          ref => 'd4/d7c/explorer_8hh'
        },
        {
          name => 'iostream'
        },
        {
          name => 'SDL_image.h'
        },
        {
          name => 'game.hh',
          ref => 'd3/d0e/game_8hh'
        }
      ],
      included_by => [
      ],
      functions => {
        members => [
          {
            kind => 'function',
            name => 'operator++',
            virtualness => 'non_virtual',
            protection => 'public',
            static => 'no',
            brief => {},
            detailed => {},
            type => 'explorerData',
            const => 'no',
            volatile => 'no',
            parameters => [
              {
                declaration_name => 'save',
                type => 'explorerData &'
              }
            ]
          }
        ]
      },
      brief => {},
      detailed => {}
    },
    {
      name => 'init.cc',
      includes => [
        {
          name => 'scenes/init.hh',
          ref => 'dd/d82/init_8hh'
        },
        {
          name => 'SDL_image.h'
        },
        {
          name => 'game.hh',
          ref => 'd3/d0e/game_8hh'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'notepad.cc',
      includes => [
        {
          name => 'scenes/notepad.hh',
          ref => 'd4/d54/notepad_8hh'
        },
        {
          name => 'fstream'
        },
        {
          name => 'iostream'
        },
        {
          name => 'SDL_image.h'
        },
        {
          name => 'game.hh',
          ref => 'd3/d0e/game_8hh'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'scene.cc',
      includes => [
        {
          name => 'scenes/scene.hh',
          ref => 'd5/dd8/scene_8hh'
        },
        {
          name => 'iostream'
        },
        {
          name => 'SDL.h'
        },
        {
          name => 'SDL_image.h'
        },
        {
          name => 'game.hh',
          ref => 'd3/d0e/game_8hh'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    },
    {
      name => 'shitcord.cc',
      includes => [
        {
          name => 'scenes/shitcord.hh',
          ref => 'd1/da8/shitcord_8hh'
        },
        {
          name => 'SDL_image.h'
        },
        {
          name => 'game.hh',
          ref => 'd3/d0e/game_8hh'
        }
      ],
      included_by => [
      ],
      brief => {},
      detailed => {}
    }
  ],
  groups => [
  ],
  pages => [
  ]
};
1;
