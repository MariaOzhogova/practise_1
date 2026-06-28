import cv2
# загружаем изображение (cv2.imread()), показываем оригинал (cv2.imshow())
# размываем для подавления шума и переводим в HSV (cv2.cvtColor())
# ищем границы зелёного, создаём маску, находим контуры
# через цикл обрабатываем каждый зелёный объект: рисуем синюю рамку (cv2.rectangle())
# и красную точку в центре (cv2.circle())
# ищем границы жёлтого, создаём маску, находим контуры
# через цикл обрабатываем каждый жёлтый объект: рисуем зелёную рамку (cv2.rectangle())
# и красную точку в центре (cv2.circle())
# выводим результат
import numpy as np
image = cv2.imread("test2.jpg")
cv2.imshow("original", image)
cv2.waitKey(0)
blurred_image = cv2.GaussianBlur(image, (11, 11), 0)
hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV)
hsv_min_green = np.array((36, 25, 25), np.uint8)
hsv_max_green = np.array((70, 255, 255), np.uint8)
green_mask = cv2.inRange(hsv_image, hsv_min_green, hsv_max_green)
contours_green, hierarchy_green = cv2.findContours(
    green_mask.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE
)
for contour in contours_green:
    if cv2.contourArea(contour) < 500:
        continue
    x, y, w, h = cv2.boundingRect(contour)
    cx = int(x + w / 2)
    cy = int(y + h / 2)
    cv2.rectangle(image, (x, y), (x + w, y + h), (255, 0, 0), 3)
    cv2.circle(image, (cx, cy), 8, (0, 0, 255), -1)
    print(f"Зелёный объект: x={x}, y={y}, w={w}, h={h}, центр=({cx}, {cy})")
hsv_min_yellow = np.array((20, 100, 100), np.uint8)
hsv_max_yellow = np.array((36, 255, 255), np.uint8)
yellow_mask = cv2.inRange(hsv_image, hsv_min_yellow, hsv_max_yellow)
contours_yellow, hierarchy_yellow = cv2.findContours(
    yellow_mask.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE
)
for contour in contours_yellow:
    if cv2.contourArea(contour) < 500:
        continue
    x, y, w, h = cv2.boundingRect(contour)
    cx = int(x + w / 2)
    cy = int(y + h / 2)
    cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 3)
    cv2.circle(image, (cx, cy), 8, (0, 0, 255), -1)
    print(f"Жёлтый объект: x={x}, y={y}, w={w}, h={h}, центр=({cx}, {cy})")
cv2.imshow("result", image)
cv2.waitKey(0)
cv2.destroyAllWindows()
