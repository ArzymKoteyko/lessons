from telebot import TeleBot, types
import main 

Test_Boi = TeleBot('813653803:AAH4nAQHNg3XqZYE2wDvXR_cPCea8LwEERE')

def show_zodiak_buttons_on(message):
    keyboard = types.InlineKeyboardMarkup()
    for zod in main.zods:
        key_zod = types.InlineKeyboardMarkup(text = zod, callback_data = 'zod')
        keyboard.add(key_zod)

    Test_Boi.send_message(message.from_user.id, 'выбери свой знак задиака', reply_markupkeyboard)



@Test_Boi.message_handler(content_types=['text'])
def get_text_message(message):
    if message.text   == r'\hello':
        Test_boi.send_message(message.from_user.id, 'Hi!')
        show_zodiak_buttons_on(message)
    elif message.text == r'\help' :
        Test_boi.send_message(message.from_user.id, r'напиши \hello')

@Test_Boi.callback_query_handler(func = lambda call:True)
def callback_worker(call):
    if call_data == 'test':
        msg = main.getPrediction()
        Test_Boi.send_message(call.message.chat.id, msg)

Test_Boi.polling(none_stop = True, interval = 0)