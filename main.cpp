	

     
    #include <allegro5\allegro.h>
    #include <allegro5\allegro_image.h>
    #include <allegro5/allegro_font.h>
    #include <allegro5/allegro_ttf.h>
    #include <stdio.h>
    #include <iostream>
    #include "World.h"
    #include "Container.h"
    #include "Item.h"
    #include "DynamicItem.h"
    #include "MouseHandler.h"
    #include "EntityCharacter.h"
    #include "Button.h"
    #include <vector>
     
    Container *deltaCont;
    EntityCharacter entityChar;
    World world;
    MouseHandler m;
    DynamicItem heldItem;
     
    bool isHoldingItem=false;
    bool titleScreen=true;
    bool userQuit=false;
                                            bool battle=false;
                                            bool inventory[3] = {false, false, false};
    //bool intro=true;
    bool redraw=true;
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_EVENT_QUEUE *queue2;
    ALLEGRO_BITMAP *title[2];
    ALLEGRO_BITMAP *hud[12];
    ALLEGRO_BITMAP *item[256];
    ALLEGRO_FONT *font;
    ALLEGRO_KEYBOARD_STATE state;
    int displayX = 640;
    int displayY = 480;
    ALLEGRO_TIMER *timer = NULL;
    int FPS = 60;
     
    //                                                 0,0 0,1    1,0 1,1
    /*void craftItem(int recipe[2][2], int quantity[2][2], int result, Container *co) // {5, 5} {5, 5}
    {
            if(co->items[0]->iD == recipe[0][0] && co->items[0]->stack == quantity[0][0])
            {
                    if(co->items[1]->iD == recipe[0][1] && co->items[1]->stack == quantity[0][0])
                    {
                            if(co->items[2]->iD == recipe[1][0] && co->items[2]->stack == quantity[0][0])
                            {
                                    if(co->items[3]->iD == recipe[1][1] && co->items[3]->stack == quantity[0][0])
                                    {
                                            for(int i = 0; i < 4; i++)
                                            {
                                                    co->items[i]->iD == 0;
                                                    co->modifyItem(i, 0, 0);
                                                    co->items[0]->iD ==
                                            }
                                    }
                            }
                    }
            }
    }
     
    void assignInventoryItem(Container *c, int b)
    {
                                                                                                                                                                                   
    }
     
    int grabInventoryItem(Container *c)
    {
            if(c->loopContainerSpace() != -1)
            {
            if(c->items[c->loopContainerSpace()]->selectItem() == 2 && !isHoldingItem)
            {
     
                    heldItem.iD = c->getItemId();
                    heldItem.stack = c->items[c->loopContainerSpace()]->stack;
                    heldItem.init();
                    c->modifyItem(c->loopContainerSpace(), 0, 0);
                    isHoldingItem=true;    
                    deltaCont = c;
                    return 2;
            }
            if(isHoldingItem == true)
            {
                    if(c->items[c->loopContainerSpace()]->selectItem() == 3)
                    {
     
                                    if(heldItem.stack < c->items[c->loopContainerSpace()]->maxStack)
                                    {
                                            if(heldItem.iD == c->items[c->loopContainerSpace()]->iD)
                                            {
                                                    if(c->items[c->loopContainerSpace()]->stack > 0)
                                                    {
                                                            c->deltaItem=c->loopContainerSpace();
                                                            c->items[c->loopContainerSpace()]->stack--;
                                                            heldItem.stack = heldItem.stack++;     
                                                    }
                                                    else
                                                    {
                                                            c->modifyItem(c->loopContainerSpace(), 0, 0);
                                                    }              
                                            }
                            }
                    }
            }
            else if(c->items[c->loopContainerSpace()]->selectItem() == 3)
            {
                    c->items[c->loopContainerSpace()]->stack--;
                    heldItem.iD = c->getItemId();
                    heldItem.stack = heldItem.stack++;
                    heldItem.init();
                    isHoldingItem=true;    
                    deltaCont = c;
                    return 3;
            }
            }
            return 0;
    }
    void defineMultipleContainers(Container *c, Container *c2, int b, int stack, Container *c3)
    {
            if(c->checkIfInBounds() == true)
            {
                    if(c == c3)
                    {
                    c->assignItem(b, stack);
                    }
                    else
                    {
                            int k=0;
                            for(int i = 0; i < c->size; i++)
                            {
                                    if(c->items[i]->selectItem() == 1)
                                    {
                                            if(c->items[i]->iD != 0 && c->items[i]->iD != b)
                                            {
                                                    if(c2->items[c2->deltaItem]->iD != 0)
                                                    {
                                                            c2->items[c2->deltaItem]->stack += heldItem.stack;
                                                    }
                                                    else
                                                    {
                                                    c2->items[c2->deltaItem]->iD = c->items[i]->iD;
                                                    c2->items[c2->deltaItem]->stack = c->items[i]->stack;
                                                    c2->modifyItem(c2->deltaItem, 0, c->items[i]->iD);
                                                    c->items[i]->iD = b;
                                                    c->items[i]->stack = stack;
                                                    c->modifyItem(i, 0, b);
                                                    }
                                            }
                                            else if (c->items[i]->iD == 0)
                                            {                              
                                                    c->items[i]->iD = b;
                                                    c->items[i]->stack = stack;
                                                    c->modifyItem(i, 0, b);
                                            }                              
                                            else if(c->items[i]->iD == b)
                                            {
                                                    c->items[i]->stack = c->items[i]->stack + stack;
                                            }
                                    }
                                    if(c->items[i]->selectItem() == 0)
                                    {
                                            k++;
                                            if(k == c->size)
                                            {
                                                    c2->items[c->deltaItem]->stack = stack;
                                                    c2->items[c2->deltaItem]->iD = b;
                                                    c2->modifyItem(c2->deltaItem, 0, b);
                                            }
                                    }
                            }
                    }
            }
            else if (c == c3 && c2->checkIfInBounds() == false)
            {
                    c->items[c->deltaItem]->stack += stack;
                    c->items[c->deltaItem]->iD = b;
                    c->modifyItem(c->deltaItem, 0, b);
            }
     
            else if(c2->checkIfInBounds() == true)
            {
                    if(c2 == c3)
                    {
                    c2->assignItem(b, stack);
                    }
                    else
                    {
                            int k=0;
                            for(int i = 0; i < c2->size; i++)
                            {
                                    if(c2->items[i]->selectItem() == 1)
                                    {
                                            if(c2->items[i]->iD != 0 && c2->items[i]->iD != b)
                                            {
                                                    if(c->items[c->deltaItem]->iD != 0)
                                                    {
                                                            c->items[c->deltaItem]->stack += heldItem.stack;
                                                    }
                                                    else
                                                    {
                                                    c->items[c->deltaItem]->iD = c2->items[i]->iD;
                                                    c->items[c->deltaItem]->stack = c2->items[i]->stack;
                                                    c->modifyItem(c->deltaItem, 0, c2->items[i]->iD);
                                                    c2->items[i]->iD = b;
                                                    c2->items[i]->stack = stack;
                                                    c2->modifyItem(i, 0, b);
                                                    }
                                            }
                                            else if (c2->items[i]->iD == 0)
                                            {                              
                                                    c2->items[i]->iD = b;
                                                    c2->items[i]->stack = stack;
                                                    c2->modifyItem(i, 0, b);
                                            }                              
                                            else if(c2->items[i]->iD == b)
                                            {
                                                    c2->items[i]->stack = c2->items[i]->stack + stack;
                                            }
                                    }
                                    if(c2->items[i]->selectItem() == 0)
                                    {
                                            k++;
                                            if(k == c2->size)
                                            {
                                                    c->items[c->deltaItem]->stack = stack;
                                                    c->items[c->deltaItem]->iD = b;
                                                    c->modifyItem(c->deltaItem, 0, b);
                                            }
                                    }
                            }
                    }
            }
            else if (c2 == c3 && c->checkIfInBounds() == false)
            {
                    c2->items[c->deltaItem]->stack += stack;
                    c2->items[c2->deltaItem]->iD = b;
                    c2->modifyItem(c2->deltaItem, 0, b);
            }
    }*/
     
    void defineItems()
    {
            font = al_load_ttf_font("visitor1.ttf", 16, 0);
            item[0] = al_load_bitmap("Item_TimPangBook.png");
            item[1] = al_load_bitmap("Item_TimPangVirginity.png");
            item[2] = al_load_bitmap("Item_WaterBottle.png");
            item[3] = al_load_bitmap("Item_ScrapMetal.png");
            item[4] = al_load_bitmap("Item_ScrapWood.png");
            item[5] = al_load_bitmap("Item_ScrapCloth.png");
            item[6] = al_load_bitmap("Item_Plastik.png");
            item[7] = al_load_bitmap("Item_SuperGlue.png");
            item[8] = al_load_bitmap("Item_SuperSuperGlue.png");
            item[9] = al_load_bitmap("Item_SuperSuperSuperGlue.png");
            item[10] = al_load_bitmap("Item_SuperSuperSuperSuperGlue.png");
            item[11] = al_load_bitmap("Item_Mechanism.png");
            item[12] = al_load_bitmap("Item_ScrapCloth.png");
            item[13] = al_load_bitmap("Item_Mechanims.png");
            item[14] = al_load_bitmap("Item_TimPangBook.png");
            item[15] = al_load_bitmap("Item_TimPangBook.png");
            item[16] = al_load_bitmap("Item_TimPangBook.png");
            item[17] = al_load_bitmap("Item_TimPangBook.png");
            item[18] = al_load_bitmap("Item_TimPangBook.png");
            item[171] = al_load_bitmap("Item_Rarity1.png");
            item[172] = al_load_bitmap("Item_Rarity2.png");
            item[173] = al_load_bitmap("Item_Rarity3.png");
            item[174] = al_load_bitmap("Item_Rarity4.png");
            item[175] = al_load_bitmap("Item_Rarity5.png");
            item[176] = al_load_bitmap("Item_Rarity6.png");
            item[177] = al_load_bitmap("Item_Rarity7.png");
            item[178] = al_load_bitmap("Item_Rarity8.png");
    }
    void init()
    {
            al_init();
            srand(time(0));
            if(!al_init())
            {
                    titleScreen = false;
            }
            al_install_keyboard();
            al_install_mouse();
            al_init_image_addon();
            al_init_font_addon();
            al_init_ttf_addon();
            timer = al_create_timer(1.0 / FPS);
            display = al_create_display(displayX, displayY);
            queue = al_create_event_queue();
            queue2 = al_create_event_queue();
            al_register_event_source(queue, al_get_display_event_source(display));
            al_register_event_source(queue, al_get_timer_event_source(timer));
            al_register_event_source(queue, al_get_mouse_event_source());
            world.init();
            //entityChar.init(1);
            heldItem.init();
            defineItems();
            al_start_timer(timer);
            //intro=false;
     
    }
     
     
    bool handle(int key)
    {
            al_get_keyboard_state(&state);
            if(al_key_down(&state, key))
            {
                    return true;
            }
            else
            {
                    return false;
            }
    }
     
    class Square
    {
    public:
            Square();
            int height, width, xpos, ypos; 
            void update(), Delete(), reset();
            ALLEGRO_COLOR color;
    private:
            int timer, speed;
    protected:     
    };
     
    Square::Square()
    {
            Square::reset();
    }
    void Square::reset()
    {
            Square::height=rand() % 60 + 30;
            Square::width=rand() % 45 + 30;
            Square::color=al_map_rgb(rand() % 20 + 220,rand() % 20 + 160,rand() % 5+1);
            Square::timer=0;
            Square::xpos=rand() % 650 - 10;
            Square::ypos=480+rand() % 600 + 40;
            Square::speed=rand() % 5 + 5;
    }
    void Square::update()
    {
            if(Square::timer<600)
            {
                    Square::timer++;
                    Square::ypos-=speed;
                    Square::color.a+=5;
                    if(Square::ypos < 50)
     
                    {
                            timer=601;
                    }
            }
            else
            {
                    Square::reset();
            }
            for(int i=0; i<Square::width; i++)             
            {
                    for(int j=0; j<Square::height; j++)
                    {
                    al_draw_pixel(Square::xpos+i, Square::ypos+j, Square::color);
                    }
            }
    }
     
    void Square::Delete()
    {
            delete this;
    }
     
    void assignContainerSlot(int i, int j, Container cont)
    {
            cont.items[i]->iD=j;
    }
     
     
    int main()
    {
            init();
            title[0] = al_load_bitmap("titleBG.png");
            title[1] = al_load_bitmap("promptEnter.png");
            hud[0] = al_load_bitmap("WorldMapGUI.png");
            hud[1] = al_load_bitmap("InventoryGUI.png");
            hud[2] = al_load_bitmap("SkillGUI.png");
            int randFrame = 0;
     
     
            float hInc = 0, wInc = 0,  rand1 = 0, rand2 = 0;
            while(true)
            {
     
                    ALLEGRO_EVENT ev;
                    al_wait_for_event(queue, &ev);
                    if(ev.timer.source == timer)
                    {
                    al_clear_to_color(al_map_rgb(0,0,0));
                   
                    al_draw_bitmap(title[0], 0, 0, 0);
            //      al_draw_bitmap(title[1], 240, 380, 0);
                   
                    if(randFrame==0)
                    {
                            rand1 = rand() % 5 + 190;
                            rand2 = rand() % 3 + 85;
                            wInc = (rand1 - 160) / 180;
                            hInc = (rand2 - 60) / 80;
                    }
                    if(randFrame==80)
                    {
                            randFrame=-1;          
                    }
                    if(randFrame > 40)
                    {
                            float temp1 = (40.0*wInc);
                            float temp2 = (40.0*hInc);
                            al_draw_scaled_bitmap(title[1], 0, 0, 160, 60 ,240-0.5*(temp2-(randFrame/7)) ,385-0.5*(temp1-(wInc*(randFrame-40))) ,(160.0f+temp1)-(wInc*(randFrame-40)) ,(60.0f+temp2)-(hInc*(randFrame-40)) ,0);
                    }
                    else
                    {
                            al_draw_scaled_bitmap(title[1], 0, 0, 160, 60 ,240-(randFrame/7) ,385-0.5*(wInc*randFrame) ,160.0f+(wInc*randFrame) ,60.0f+(hInc*randFrame) ,0);
                    }
     
                    if(handle(ALLEGRO_KEY_ENTER))
                    {
                            break;
                    }
     
                    randFrame++;
                    al_flip_display();
                    }
            }
            Button *startButton = new Button(230, 280, 90, 180, al_load_bitmap("buttonplay.png"), al_load_bitmap("buttonplayactive.png"), al_load_bitmap("buttonplay.png"));
            Button *optionButton = new Button(40, 280, 90, 180, al_load_bitmap("buttonoption.png"), al_load_bitmap("buttonoptionactive.png"), al_load_bitmap("buttonoption.png"));
            //Button *quitButton = new Button(0, 400, 50, 50, al_load_bitmap("button1idle.png"), al_load_bitmap("button1active.png"), al_load_bitmap("button1click.png"));
            Button *creditsButton = new Button(420, 280, 90, 180, al_load_bitmap("buttoncredits.png"), al_load_bitmap("buttoncreditsactive.png"), al_load_bitmap("buttoncredits.png"));
            Button *inventoryButton = new Button(437, 434, 40, 60, al_load_bitmap("buttonInventory.png"), al_load_bitmap("buttonInventoryActive.png"), al_load_bitmap("buttonInventory.png"));
            Button *quitWorldButton = new Button(592, 434, 40, 40, al_load_bitmap("buttonQuitWorld.png"), al_load_bitmap("buttonQuitWorldActive.png"), al_load_bitmap("buttonQuitWorld.png"));
            Button *optionWorldButton = new Button(592, 389, 40, 40, al_load_bitmap("buttonOptionWorld.png"), al_load_bitmap("buttonOptionWorldActive.png"), al_load_bitmap("buttonOptionWorld.png"));
            Button *skillButton = new Button(512, 434, 40, 60, al_load_bitmap("buttonSkill.png"), al_load_bitmap("buttonSkillActive.png"), al_load_bitmap("buttonSkill.png"));
            Button *inventorySortQuest = new Button(340, 48, 60, 60, al_load_bitmap("inventoryButton_Quest.png"), al_load_bitmap("inventoryButton_QuestActive.png"), al_load_bitmap("inventoryButton_Quest.png"));
            Button *inventorySortCC = new Button(340, 113, 40, 60, al_load_bitmap("inventoryButton_Template.png"), al_load_bitmap("inventoryButton_TemplateActive.png"), al_load_bitmap("inventoryButton_Template.png"));
            Button *inventorySortEquip = new Button(340, 178, 60, 60, al_load_bitmap("inventoryButton_Template.png"), al_load_bitmap("inventoryButton_TemplateActive.png"), al_load_bitmap("inventoryButton_Template.png"));
            Button *inventorySortDelete = new Button(340, 243, 60, 60, al_load_bitmap("inventoryButton_Delete.png"), al_load_bitmap("inventoryButton_DeleteActive.png"), al_load_bitmap("inventoryButton_Delete.png"));
     
     
            Container *invCont = new Container(4, 4, 25, 48, 48, 5);
            Container *craftingCont = new Container(12, 12, 4, 432, 96, 2);
            Container *resultCont = new Container(0, 0, 1, 530, 154, 1);
            invCont->initate();
            craftingCont->initate();
            invCont->setId(12, 5);
            invCont->setId(3, 4);
            invCont->setId(9, 3);
            invCont->setId(10, 3);
            invCont->setStack(9, 259);
            invCont->setStack(10, 50);
            craftingCont->setId(1, 8);
            int focusButton=1;
            while(!userQuit)
            {                      
                            m.handleMouse();
                            ALLEGRO_EVENT ev;
                            al_wait_for_event(queue, &ev);
                            if(ev.timer.source == timer)
                            {                      
                                    redraw = true;
                                   
     
                                    //------------------------ TITLE SCREEN
                                    if(titleScreen)
                                    {
                                    startButton->isClicked();
                                    creditsButton->isClicked();
                                    optionButton->isClicked();
                                    if(startButton->state==2)
                                    {
                                            titleScreen=false;
                                    }
                                    if(startButton->state==1)
                                    {
                                            focusButton=1;
                                    }
                                    else if(optionButton->state==1)
                                    {
                                            focusButton=2;
                                    }
                                    else if(creditsButton->state==1)
                                    {
                                            focusButton=3;
                                    }
                                    else
                                    {
                                            focusButton = 0;
                                    }
     
                                    }
     
                                    //-------------------------- INGAME
                                    if(!titleScreen)
                                    {
                                            //al_get_keyboard_state(&state);
                                            inventoryButton->isClicked();
                                            quitWorldButton->isClicked();
                                            optionWorldButton->isClicked();
                                            skillButton->isClicked();
                                            //Character Movement
                                            if(handle(ALLEGRO_KEY_UP))
                                            {
                                                    entityChar.moveCharacter(1);
                                            }
                                            if(handle(ALLEGRO_KEY_RIGHT))
                                            {
                                                    entityChar.moveCharacter(2);
                                            }
                                            if(handle(ALLEGRO_KEY_DOWN))
                                            {
                                                    entityChar.moveCharacter(3);
                                            }
                                            if(handle(ALLEGRO_KEY_LEFT))
                                            {
                                                    entityChar.moveCharacter(4);
                                            }
     
                                           
                                           
                                           
     
     
     
     
     
     
                                            if(inventory[1])
                                            {
                                                    if(skillButton->isClicked()!=2)
                                                    {
                                                            skillButton->hasClicked=false;
                                                    }
                                                    //Skill Operations ----------------------------------------------------
     
     
                                                   
     
     
                                                    //End of Skill Operations ---------------------------------------------
                                                    if(skillButton->hasClicked==false && skillButton->isClicked()==2)
                                                    {
                                                            inventory[1]=false;
                                                            skillButton->hasClicked=true;
                                                    }
                                            }
                                            if(inventory[0])
                                            {                      
                                                   
                                                    if(inventoryButton->isClicked()!=2)
                                                    {
                                                            inventoryButton->hasClicked=false;
                                                    }
                                                    //InventoryOperations ---------------------------------------------------
     
                                                    m.isClicked();
                                                    invCont->initate();
                                                    craftingCont->initate();
                                                    resultCont->initate();
                                                   
                                                    /*{
                                                    if(invCont->selectItem(2) != -1)
                                                    {
                                                            heldItem.iD = invCont->items[invCont->selectItem(2)]->iD;
                                                            heldItem.stack = invCont->items[invCont->selectItem(2)]->stack;
                                                            heldItem.init();
                                                            invCont->modifyItem(invCont->selectItem(2), 0, 0);
                                                            isHoldingItem=true;                                                                                                                                                    
                                                            deltaCont = invCont;
                                                    }
                                                    if(craftingCont->selectItem(2) != -1)
                                                    {
                                                            heldItem.iD = craftingCont->items[craftingCont->selectItem(2)]->iD;    
                                                            heldItem.stack = craftingCont->items[craftingCont->selectItem(2)]->stack;
                                                            heldItem.init();
                                                            craftingCont->modifyItem(craftingCont->selectItem(2), 0, 0);
                                                            isHoldingItem=true;                                                                                                                                                                                            
                                                            deltaCont = craftingCont;
                                                    }
                                                    if(invCont->selectItem(1) != -1)
                                                    {
                                                            heldItem.iD = invCont->items[invCont->selectItem(1)]->iD;
                                                            heldItem.stack = 1;
                                                            heldItem.init();
                                                            invCont->items[invCont->selectItem(1)]->stack--;
                                                            if(invCont->items[invCont->selectItem(1)]->stack==0)
                                                            {
                                                                    invCont->modifyItem(invCont->selectItem(1), 0, 0);
                                                            }
                                                            isHoldingItem=true;                                                                                                                                                    
                                                            deltaCont = invCont;
                                                    }
                                                    if(craftingCont->selectItem(1) != -1)
                                                    {
                                                            heldItem.iD = craftingCont->items[craftingCont->selectItem(1)]->iD;    
                                                            heldItem.stack = 1;
                                                            heldItem.init();
                                                            craftingCont->items[craftingCont->selectItem(1)]->stack--;
                                                            if(craftingCont->items[craftingCont->selectItem(1)]->stack==0)
                                                            {
                                                                    craftingCont->modifyItem(craftingCont->selectItem(1), 0, 0);
                                                            }
                                                            isHoldingItem=true;                                                                                                                                                                                            
                                                            deltaCont = craftingCont;
                                                    }
                                                    }*/            
                                                    //define usable vector
                                                    std::vector<Item *> *itemSlots = new std::vector<Item *>;
                                                    for(int i=0; i<invCont->size; i++)
                                                    {
                                                            itemSlots->push_back(invCont->items[i]);
                                                    }
                                                    for(int i=0; i<craftingCont->size; i++)
                                                    {
                                                            itemSlots->push_back(craftingCont->items[i]);
                                                    }
                                                    for(int i=0; i<resultCont->size; i++)
                                                    {
                                                            itemSlots->push_back(resultCont->items[i]);
                                                    }
                                                    // do stuff
                                                    for(int i=0; i<itemSlots->size(); i++)
                                                    {
                                                            if(heldItem.itemSelected==false && heldItem.click==false)
                                                            {
                                                                    if((*itemSlots)[i]->checkInBounds() == true && (*itemSlots)[i]->iD != 0 && (m.state == 1 || m.state == 2))
                                                                    {
     
     
                                                                            heldItem.itemSelected = true;
                                                                            heldItem.activeClick = true;
                                                                            heldItem.click = true;
                                                                            heldItem.containerSlot=i;
                                                                            if(m.state == 2)
                                                                            {
                                                                                    heldItem.holdingItem->iD = (*itemSlots)[i]->iD;
                                                                                    heldItem.holdingItem->init();
                                                                                    heldItem.holdingItem->stack= 1;
                                                                                    heldItem.rightClick=true;
                                                                                    heldItem.accessButton = 2;
                                                                                    (*itemSlots)[i]->stack--;
                                                                            }
                                                                            else if(m.state == 1)
                                                                            {
                                                                                    (*itemSlots)[i]->pickUp();
                                                                                   
                                                                            }
                                                                           
                                                                    }                                                      
                                                            }
                                                            if(heldItem.itemSelected==true)
                                                            {
                                                                    if(heldItem.activeClick == true && m.state == 0)
                                                                    {
                                                                            heldItem.activeClick = false;                                  
                                                                    }
                                                                    if(heldItem.rightClick == true && m.state == 0)
                                                                    {
                                                                            heldItem.rightClick = false;                                   
                                                                    }
                                                            }
                                                            if(heldItem.click == true && m.state == 0 && heldItem.itemSelected == false)
                                                            {
                                                                    heldItem.click = false;
                                                            }
                                                            if(heldItem.activeClick == false && heldItem.click == true && (m.state == 1 || m.state == 2) && heldItem.itemSelected==true)
                                                            {
                                                            //leftClick release
                                                                    if((*itemSlots)[i]->checkInBounds() == true)
                                                                    {
                                                                            if(m.state == 1)
                                                                            {
                                                                                    if((*itemSlots)[i]->iD != 0 && (*itemSlots)[i]->iD != heldItem.holdingItem->iD)
                                                                                    {
                                                                                            if(heldItem.accessButton == 2)
                                                                                            {
                                                                                                    (*itemSlots)[heldItem.containerSlot]->stack += heldItem.holdingItem->stack;
                                                                                            }
                                                                                            else
                                                                                            {
                                                                                                    (*itemSlots)[heldItem.containerSlot]->iD = (*itemSlots)[i]->iD;
                                                                                                    (*itemSlots)[heldItem.containerSlot]->stack = (*itemSlots)[i]->stack;
                                                                                                    (*itemSlots)[heldItem.containerSlot]->init();
                                                                                            }
                                                                                    }
                                                                                    if((*itemSlots)[i]->iD == heldItem.holdingItem->iD)
                                                                                    {
                                                                                            (*itemSlots)[i]->stack += heldItem.holdingItem->stack;
                                                                                    }
                                                                                    else if(heldItem.accessButton !=2 || (*itemSlots)[i]->iD == 0)
                                                                                    {
                                                                                            (*itemSlots)[i]->iD=heldItem.holdingItem->iD;
                                                                                            (*itemSlots)[i]->stack=heldItem.holdingItem->stack;
                                                                                            (*itemSlots)[i]->init();
                                                                                    }
                                                                                    heldItem.itemSelected=false;
                                                                            }
                                                                            if((*itemSlots)[i]->iD == heldItem.holdingItem->iD && m.state == 2 && heldItem.rightClick == false)
                                                                            {
                                                                                    (*itemSlots)[heldItem.containerSlot]->stack--;
                                                                                    heldItem.holdingItem->stack++;
                                                                                    heldItem.rightClick = true;
                                                                            }
     
                   
                                                                           
                                                                    }
                                                            }
                                                            (*itemSlots)[i]->updateStack();
                                                    }
                                                   
                                                    //Container handling end
     
                                                    //update the containers!!
                                                    invCont->items.assign((*itemSlots).begin(), (*itemSlots).begin()+invCont->size);
                                                    craftingCont->items.assign(((*itemSlots).begin()+invCont->size), ((*itemSlots).begin()+invCont->size)+craftingCont->size);
                                                    resultCont->items.assign(((*itemSlots).begin()+invCont->size+craftingCont->size), ((*itemSlots).begin()+invCont->size+craftingCont->size)+resultCont->size);
                                                    invCont->update();
                                                    craftingCont->update();
                                                    resultCont->update();
                                            /*      if(heldItem.activeClick == false && heldItem.click == true && m.state == 1)
                                                    {
                                                            //LeftClick
                                                    }
                                                    if(heldItem.activeClick == false && heldItem.click == true && m.state == 2)
                                                    {
                                                            //rightClick
                                                    }*/
     
                                                    // end of doing stuff
                                                    itemSlots->clear();
                                                    delete itemSlots;
                                                    // end of clearing vector
                                                            /*{
                                                                    if(invCont->checkIfInBounds() == true)
                                                                    {
                                                                            for(int i=0; i<invCont->size; i++)
                                                                            {                                                                      
                                                                                    if(invCont->items[i]->checkInBounds() == true)
                                                                                    {              
                                                                                            if(invCont->items[i]->stack > 0 && invCont->items[i]->iD == heldItem.holdingItem->iD)
                                                                                            {              
                                                                                                    heldItem.holdingItem->stack++;
                                                                                                    invCont->items[i]->stack--;
                                                                                                    if(invCont->items[i]->stack == 0)
                                                                                                    {
                                                                                                            invCont->setId(i, 0);
                                                                                                    }
                                                                                            }
                                                                                    }
     
                                                                            }
                                                                    }
                                                                    if(craftingCont->checkIfInBounds() == true)
                                                                    {
                                                                            for(int i=0; i<craftingCont->size; i++)
                                                                            {                                                                      
                                                                                    if(craftingCont->items[i]->checkInBounds() == true)
                                                                                    {              
                                                                                            if(craftingCont->items[i]->stack > 0 && craftingCont->items[i]->iD == heldItem.holdingItem->iD)
                                                                                            {              
                                                                                                    heldItem.holdingItem->stack++;
                                                                                                    craftingCont->items[i]->stack--;
                                                                                                    if(craftingCont->items[i]->stack == 0)
                                                                                                    {
                                                                                                            craftingCont->setId(i, 0);
                                                                                                    }
                                                                                            }
     
                                                                                    }
                                                                            }
                                                                    }
                                                            }*/
     
                                                            /*{
                                                                    heldItem.itemSelected = false;
                                                                    if(invCont->checkIfInBounds() == true)
                                                                    {
                                                                            for(int i=0; i<invCont->size; i++)
                                                                            {
                                                                                   
                                                                                    if(invCont->items[i]->checkInBounds() == true)
                                                                                    {                                                                                      
                                                                                            if(invCont->items[i]->iD != 0 && heldItem.originCont == craftingCont)
                                                                                            {
                                                                                                    craftingCont->setId(heldItem.containerSlot, invCont->items[i]->iD);
                                                                                                    craftingCont->setStack(heldItem.containerSlot, invCont->items[i]->stack);
                                                                                            }
                                                                                            else if(invCont->items[i]->iD != 0)
                                                                                            {
                                                                                                    invCont->setId(heldItem.containerSlot, invCont->items[i]->iD);
                                                                                            }
                                                                                            invCont->setId(i, heldItem.holdingItem->iD);
                                                                                            invCont->setStack(i, heldItem.holdingItem->stack);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                            b++;
     
                                                                                    }
                                                                                    if(b == invCont->size)
                                                                                    {
                                                                                            invCont->setId(heldItem.containerSlot, heldItem.holdingItem->iD);
                                                                                            invCont->setStack(heldItem.containerSlot, heldItem.holdingItem->stack);
                                                                                    }
     
                                                                            }
                                                                    }
                                                                    if(craftingCont->checkIfInBounds() == false && invCont->checkIfInBounds() == false && heldItem.originCont == invCont)
                                                                    {
                                                                            invCont->setId(heldItem.containerSlot, heldItem.holdingItem->iD);
                                                                            invCont->setStack(heldItem.containerSlot, heldItem.holdingItem->stack);
                                                                    }
                                                                    if(craftingCont->checkIfInBounds() == false && invCont->checkIfInBounds() == false && heldItem.originCont == craftingCont)
                                                                    {
                                                                            craftingCont->setId(heldItem.containerSlot, heldItem.holdingItem->iD);
                                                                            craftingCont->setStack(heldItem.containerSlot, heldItem.holdingItem->stack);
                                                                    }
     
                                                                    if(craftingCont->checkIfInBounds() == true)
                                                                    {
                                                                            for(int i=0; i<craftingCont->size; i++)
                                                                            {
                                                                                    b++;
                                                                                    if(craftingCont->items[i]->checkInBounds() == true)
                                                                                    {
                                                                                            if(craftingCont->items[i]->iD != 0 && heldItem.originCont == invCont)
                                                                                            {
                                                                                                    invCont->setId(heldItem.containerSlot, craftingCont->items[i]->iD);
                                                                                                    invCont->setStack(heldItem.containerSlot, craftingCont->items[i]->iD);
                                                                                            }
                                                                                            else if(craftingCont->items[i]->iD != 0)
                                                                                            {
                                                                                                    craftingCont->setId(heldItem.containerSlot, craftingCont->items[i]->iD);
                                                                                                    craftingCont->setStack(heldItem.containerSlot, craftingCont->items[i]->stack);
                                                                                            }
                                                                                            craftingCont->setId(i, heldItem.holdingItem->iD);
                                                                                            craftingCont->setStack(i, heldItem.holdingItem->stack);
                                                                                    }
                                                                                    else
                                                                                    {
                                                                                            b++;
     
                                                                                    }
                                                                                    if(b == craftingCont->size)
                                                                                    {
                                                                                            craftingCont->setId(heldItem.containerSlot, heldItem.holdingItem->iD);
                                                                                            craftingCont->setStack(heldItem.containerSlot, heldItem.holdingItem->stack);
                                                                                    }
                                                                            }
                                                                    }
     
     
                                                            }
                                                    }*/
     
     
                                                    //ContainerHandling has ended!
                                                   
     
                                                    inventorySortQuest->isClicked();
                                                    inventorySortCC->isClicked();
                                                    inventorySortEquip->isClicked();
                                                    inventorySortDelete->isClicked();
     
     
                                                    //End of InventoryOperations --------------------------------------------
     
                                                    if(inventoryButton->hasClicked==false && inventoryButton->isClicked()==2)
                                                    {
                                                            inventory[0]=false;
                                                            inventoryButton->hasClicked=true;
                                                    }
                                            }
                                            if(inventoryButton->hasClicked == false && inventoryButton->isClicked()==2 && !inventory[0])
                                            {
                                                    inventoryButton->hasClicked = true;
                                                    inventory[0] = true;
                                                    inventory[1] = false;
                                            }
                                            if(skillButton->hasClicked == false && skillButton->isClicked()==2 && !inventory[1])
                                            {
                                                    skillButton->hasClicked = true;
                                                    inventory[1] = true;
                                                    inventory[0] = false;
                                            }
                                            if(inventoryButton->isClicked()!=2 && !inventory[0])
                                            {
                                                    inventoryButton->hasClicked=false;
                                            }
                                            if(skillButton->isClicked()!=2 && !inventory[1])
                                            {
                                                    skillButton->hasClicked=false;
                                            }
                                            if(heldItem.itemSelected==true)
                                            {
                                                    heldItem.holdingItem->x = (m.x-24);
                                                    heldItem.holdingItem->y = (m.y-24);
                                            }
     
                                    }
                            }      
                            else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
                            {
                                    break;
                                    userQuit=true;
                            }
     
                            if(al_event_queue_is_empty(queue))
                            {
                                    if(redraw)
                                    {                
                                            //-------------------------- TITLE SCREEN
                                            if(titleScreen)
                                            {
                                            al_flip_display();
                                            al_draw_bitmap(title[0], 0, 0, 0);
                                           
                                            switch (focusButton)
                                            {
                                                    case 1:
                                                            creditsButton->update();
                                                            startButton->updateScale(202.5, 135, 220, 272.5, 180, 120);
                                                            optionButton->update();
                                                            break;
                                                    case 2:
                                                            optionButton->updateScale(202.5, 135, 30, 272.5, 180, 120);
                                                            startButton->update();
                                                            creditsButton->update();
                                                            break;
                                                    case 3:
                                                            startButton->update();
                                                            creditsButton->updateScale(202.5, 135, 410, 272.5, 180, 120);
                                                            optionButton->update();
                                                            break;
                                                    default:
                                                            startButton->update();
                                                            creditsButton->update();
                                                            optionButton->update();
                                            }
                           
                                    }
                                    }
     
                                    //-------------------------- GAME
                                    if(!titleScreen)
                                    {
     
                                            world.drawWorld(entityChar);
                                            al_draw_bitmap(hud[0], 0, 384, 0);
                                            inventoryButton->update();
                                            quitWorldButton->update();
                                            optionWorldButton->update();
                                            skillButton->update();
     
                                            if(optionWorldButton->isClicked()==2)
                                            {
                                                   
                                            }
                                            if(quitWorldButton->isClicked()==2)
                                            {
                                                    break;
                                            }
                                            if(inventory[0])
                                            {
                                                    al_draw_bitmap(hud[1], 0, 0, 0);
     
                                                    inventorySortQuest->update();
                                                    inventorySortCC->update();
                                                    inventorySortEquip->update();
                                                    inventorySortDelete->update();
                                                    //invCont->selectItem();
                                                    //craftingCont->selectItem();
                                                    invCont->updateDraw(item);
                                                    craftingCont->updateDraw(item);
                                            }
                                            if(inventory[1])
                                            {
                                                    al_draw_bitmap(hud[2], 0, 0, 0);
                                            }
                                            if(heldItem.itemSelected==true)
                                            {
                                                    heldItem.holdingItem->update(item[heldItem.holdingItem->iD]);
                                                    heldItem.holdingItem->drawQuantity();
                                            }
     
                                            al_flip_display();
                                    }
                            }
    }
            return 0;
    }

